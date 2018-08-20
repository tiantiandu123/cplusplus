#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"HuffmanTree.h"  
#include<iostream>
#include<algorithm>  
#include<windows.h>  
#include<string.h>  
using namespace std;
typedef long long Longtype;//为了扩大其范围，int型能处理的范围已经不能满足，所以定义Long Long型予以表示  

struct CharInfo
{
	unsigned char _ch;//必须为unsigned，否则会造成截断，所以从-128~127调至0~255.  
	Longtype _count;
	string _code;

	CharInfo(int count = 0)
		:_ch(0)
		, _count(count)
		, _code(" ")
	{}

	CharInfo operator+(CharInfo& file)//重载+
	{
		CharInfo tmp;
		tmp._count = _count + file._count;
		return tmp;
	}

	bool operator < (CharInfo& file) const//重载<
	{
		return _count < file._count;
	}

	bool operator != (const CharInfo& file) const//重载！=
	{
		return _count != file._count;
	}
};


template<class T>
class FileCompress
{
public:
	FileCompress()
	{
		for (int i = 0; i < 256; ++i)//初始化
		{
			_infos[i]._ch = i;
		}
	}
	bool Compress(const char* filename)
	{
		//1.打开文件，统计文件字符出现的次数    
		Longtype Charcount = 0;
		assert(filename);
		FILE* fOut = fopen(filename, "rb");//之前用“r”,结果出了一点问题
		//"rb"为以二进制方式读取文件，"wb"为以二进制方式写入文件  
		assert(fOut);					//以二进制和文本打开方式区别在于：以文本打开方式会将\r\n
		//转换为\n,二进制这不会有这样的转换
		int ch = fgetc(fOut);
		while (ch != EOF) 
		{
			_infos[(unsigned char)ch]._count++;
			ch = fgetc(fOut);
			Charcount++;
		}
		//2.生成对应的huffman编码    
		GenerateHuffmanCode();
		//3.文件压缩    
		string compressFile = filename;
		compressFile += ".compress";
		FILE* fwCompress = fopen(compressFile.c_str(), "wb");//以二进制写入
		assert(fwCompress);
		fseek(fOut, 0, SEEK_SET);//重置到文件起始的位置
		ch = fgetc(fOut);
		char inch = 0;
		int pos = 0;
		while (!feof(fOut))
		{
			string& code = _infos[(unsigned char)ch]._code;
			for (size_t i = 0; i < code.size(); ++i)
			{
				inch = inch << 1;//向左移位
				if (code[i] == '1')
				{
					inch |= 1;
				}
				if (++pos == 8)//对于形成的长串字符编码的切割，每8个bit为一个字节，便于读取  
				{
					fputc(inch, fwCompress);
					inch = 0;
					pos = 0;
				}
			}
			ch = fgetc(fOut);
		}

		if (pos)//考虑到可能会有切割完，剩余的字符码不够填充8个bit位的情况  
		{
			inch = inch << (8 - pos);
			fputc(inch, fwCompress);
		}
		//4.配置文件，方便后续的解压缩；  将其字符的个数等信息存到配置文件中
		string configFile = filename;
		configFile += ".config";
		FILE *fconfig = fopen(configFile.c_str(), "wb");
		assert(fconfig);
		string infoStr;
		//char CountStr[128];
		char CountStr[128];
		_itoa(Charcount >> 32, CountStr, 10);
		fputs(CountStr, fconfig);
		fputc('\n', fconfig);
		_itoa(Charcount & 0xffffffff, CountStr, 10);
		//_itoa(Charcount & -1, CountStr, 10);
		fputs(CountStr, fconfig);
		fputc('\n', fconfig);

		CharInfo invalid;
		for (int i = 0; i < 256; i++)
		{
			if (_infos[i] != invalid)
			{
				/*	fputc(_infos[i]._ch, fconfig);
				fputc(',', fconfig);
				fputc(_infos[i]._count + '0', fconfig);
				fputc('\n', fconfig);*/
				infoStr = _infos[i]._ch;
				infoStr += ',';
				_itoa(_infos[i]._count, CountStr, 10);
				infoStr += CountStr;
				infoStr += '\n';
				fputs(infoStr.c_str(), fconfig);
			}
		}

		fclose(fOut);
		fclose(fwCompress);
		fclose(fconfig);

		return true;
	}
	//文件的解压缩 
	bool UnCompresss(const char* filename)
	{
		string configfile = filename;
		configfile += ".config";
		FILE* outConfig = fopen(configfile.c_str(), "rb");
		assert(outConfig);
		char ch = 0;
		/*char ch;*/
		Longtype Charcount = 0;
		string line = ReadLine(outConfig);
		Charcount = atoi(line.c_str());
		Charcount <<= 32;
		line.clear();
		line = ReadLine(outConfig);
		Charcount += atoi(line.c_str());
		line.clear();

		while (feof(outConfig))
			//feof()遇到文件结束，函数值为非零值，否则为0。当把数据以二进制的形式进行存放时，可能会有-1值的出现，
			//所以此时无法利用-1值（EOF）做为eof()函数判断二进制文件结束的标志。  
		{
			line = ReadLine(outConfig);
			if (!line.empty())
			{
				ch = line[0];
				_infos[(unsigned char)ch]._count += atoi(line.substr(2).c_str());
				//_infos[(unsigned char)ch]._count += atoi(line.c_str());
				line.clear();
			}
			else
			{
				line = '\n';
			}
		}

		HuffmanTree<CharInfo> ht;
		ht.CreatTree(_infos, 256, CharInfo(0));//重新建树
		HuffmanTreeNode<CharInfo>* root = ht.GetRootNode();
		string  UnCompressFile = filename;
		UnCompressFile += ".uncompress";
		FILE* fIn = fopen(UnCompressFile.c_str(), "wb");
		string CompressFile = filename;
		CompressFile += ".compress";
		FILE* fOut = fopen(CompressFile.c_str(), "rb");
		int pos = 8;
		HuffmanTreeNode<CharInfo>* cur = root;
		ch = fgetc(fOut);
		while ((unsigned char)ch != EOF)
			//while(1)
		{
			--pos;
			if ((unsigned char)ch &(1 << pos))
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
			if (cur->_left == NULL && cur->_right == NULL)
			{
				fputc(cur->_weight._ch, fIn);
				cur = root;
				Charcount--;

			}
			if (pos == 0)
			{
				ch = fgetc(fOut);
				pos = 8;
			}
			if (Charcount == 0)
			{
				break;
			}
		}


		fclose(fIn);
		fclose(fOut);
		fclose(outConfig);
		return true;
	}

protected:
	string ReadLine(FILE* fOut)//
	{
		assert(fOut);
		char ch = fgetc(fOut);
		if (feof(fOut))
		{
			return 0;
		}
		string line;
		while (ch != '\n')
		{
			line += ch;
			ch = fgetc(fOut);

			if (feof(fOut))
				break;
		}
		return line;
	}
	void GenerateHuffmanCode()
	{
		HuffmanTree<CharInfo> hft;
		CharInfo invalid;

		hft.CreatTree(_infos, 256, invalid);
		_GenerateHuffmanCode(hft.GetRootNode());
	}
protected:
	void _GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* root)//创建哈夫曼编码
	{
		if (root == NULL)
		{
			return;
		}

		_GenerateHuffmanCode(root->_left);
		_GenerateHuffmanCode(root->_right);

		if (root->_left == NULL && root->_right == NULL)
		{
			HuffmanTreeNode<CharInfo>* cur = root;
			HuffmanTreeNode<CharInfo>* parent = cur->_parent;
			string& code = _infos[cur->_weight._ch]._code;

			while (parent)
			{
				if (parent->_left == cur)//往左走+0
				{
					code += '0';
				}
				else if (parent->_right == cur)//往右走+1
				{
					code += '1';
				}
				cur = parent;
				parent = cur->_parent;
			}
			//寻找编码从叶子节点开始。
			reverse(code.begin(), code.end());
		}
	}

	//递归实现哈夫曼编码
	void _GenerateHuffmanCode_R(HuffmanTreeNode<CharInfo>* root, string code)//创建哈夫曼编码
	{
		if (root == NULL)
			return;
		_GenerateHuffmanCode_R(root->_left, code + '0');
		_GenerateHuffmanCode_R(root->_right, code + '1');
		if (root->_left == NULL&&root->_right == NULL)
		{
			_infos[root->_weight._ch]._code = code;
		}
	}
private:
	CharInfo _infos[256];
};

void TestFileCompress()
{
	cout << "一次压缩" << endl;
	FileCompress<CharInfo> fc;
	cout << "Input.txt文件压缩中...." << endl;
	cout << "压缩用时： ";
	int begin1 = GetTickCount();//记录开始时间
	fc.Compress("1.txt");//  
	int end1 = GetTickCount();//  记录结束时间
	cout << end1 - begin1 << endl << endl;//压缩时间

	cout << "Input.txt文件解压中...." << endl;;
	cout << "解压用时： ";
	int begin2 = GetTickCount();
	fc.UnCompresss("1.txt");
	int end2 = GetTickCount();
	cout << end2 - begin2 << endl << endl;//解压用时

void TestFileCompressPhoto()
{
	cout << "图片压缩" << endl;
	FileCompress<CharInfo> fc;
	cout << "捕捉.PNG文件压缩中...." << endl;
	cout << "压缩用时： ";
	int begin5 = GetTickCount();//记录开始时间
	fc.Compress("捕获.PNG");//  
	int end5 = GetTickCount();//  记录结束时间
	cout << end5 - begin5 << endl << endl;//压缩时间

	cout << "166.jpg文件解压中...." << endl;;
	cout << "解压用时： ";
	int begin6 = GetTickCount();
	fc.UnCompresss("捕获.PNG");
	int end6 = GetTickCount();
	cout << end6 - begin6 << endl << endl;//解压用时

}
