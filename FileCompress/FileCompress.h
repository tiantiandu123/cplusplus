#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"HuffmanTree.h"  
#include<iostream>
#include<algorithm>  
#include<windows.h>  
#include<string.h>  
using namespace std;
typedef long long Longtype;//Ϊ�������䷶Χ��int���ܴ���ķ�Χ�Ѿ��������㣬���Զ���Long Long�����Ա�ʾ  

struct CharInfo
{
	unsigned char _ch;//�������Ϊunsigned���������ɽضϣ����Դ�-128~127����0~255.  
	Longtype _count;
	string _code;

	CharInfo(int count = 0)
		:_ch(0)
		, _count(count)
		, _code("")
	{}

	CharInfo operator+(CharInfo& file)//����+
	{
		CharInfo tmp;
		tmp._count = _count + file._count;
		return tmp;
	}

	bool operator < (CharInfo& file) const//����<
	{
		return _count < file._count;
	}

	bool operator != (const CharInfo& file) const//���أ�=
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
		for (int i = 0; i < 256; ++i)//��ʼ��
		{
			_infos[i]._ch = i;
		}
	}
	bool Compress(const char* filename)
	{
		//1.���ļ���ͳ���ļ��ַ����ֵĴ���    
		Longtype Charcount = 0;
		assert(filename);
		FILE* fOut = fopen(filename, "rb");//֮ǰ�á�r��,�������һ������
		//"rb"Ϊ�Զ����Ʒ�ʽ��ȡ�ļ��������b����binary��"wb"Ϊ�Զ����Ʒ�ʽд���ļ�  
		assert(fOut);					//�Զ����ƺ��ı��򿪷�ʽ�������ڣ����ı��򿪷�ʽ�Ὣ\r\n
		//ת��Ϊ\n,�������ⲻ����������ת��
		//char ch = fgetc(fOut);
		int ch = fgetc(fOut);
		while (ch != EOF) 
		{
			_infos[(unsigned char)ch]._count++;
			ch = fgetc(fOut);
			Charcount++;
		}
		//2.���ɶ�Ӧ��huffman����    
		GenerateHuffmanCode();
		//3.�ļ�ѹ��    
		string compressFile = filename;
		compressFile += ".compress";
		FILE* fwCompress = fopen(compressFile.c_str(), "wb");//�Զ�����д��
		assert(fwCompress);
		fseek(fOut, 0, SEEK_SET);//���õ��ļ���ʼ��λ��
		ch = fgetc(fOut);
		char inch = 0;
		int pos = 0;
		while (!feof(fOut))
		{
			string& code = _infos[(unsigned char)ch]._code;
			for (size_t i = 0; i < code.size(); ++i)
			{
				inch = inch << 1;//������λ
				if (code[i] == '1')
				{
					inch |= 1;
				}
				if (++pos == 8)//�����γɵĳ����ַ�������иÿ8��bitΪһ���ֽڣ����ڶ�ȡ  
				{
					fputc(inch, fwCompress);
					inch = 0;
					pos = 0;
				}
			}
			ch = fgetc(fOut);
		}

		if (pos)//���ǵ����ܻ����и��꣬ʣ����ַ��벻�����8��bitλ�����  
		{
			inch = inch << (8 - pos);
			fputc(inch, fwCompress);
		}
		//4.�����ļ�����������Ľ�ѹ����  
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
	//�ļ��Ľ�ѹ�� 
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
			//feof()�����ļ�����������ֵΪ����ֵ������Ϊ0�����������Զ����Ƶ���ʽ���д��ʱ�����ܻ���-1ֵ�ĳ��֣�
			//���Դ�ʱ�޷�����-1ֵ��EOF����Ϊeof()�����ж϶������ļ������ı�־��  
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
		ht.CreatTree(_infos, 256, CharInfo(0));//���½���
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
	void _GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* root)//��������������
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
				if (parent->_left == cur)//������+0
				{
					code += '0';
				}
				else if (parent->_right == cur)//������+1
				{
					code += '1';
				}
				cur = parent;
				parent = cur->_parent;
			}
			//Ѱ�ұ����Ҷ�ӽڵ㿪ʼ��
			reverse(code.begin(), code.end());
		}
	}

	//�ݹ�ʵ�ֹ���������
	void _GenerateHuffmanCode_R(HuffmanTreeNode<CharInfo>* root, string code)//��������������
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
	cout << "һ��ѹ��" << endl;
	FileCompress<CharInfo> fc;
	cout << "Input.txt�ļ�ѹ����...." << endl;
	cout << "ѹ����ʱ�� ";
	int begin1 = GetTickCount();//��¼��ʼʱ��
	fc.Compress("1.txt");//  
	int end1 = GetTickCount();//  ��¼����ʱ��
	cout << end1 - begin1 << endl << endl;//ѹ��ʱ��

	cout << "Input.txt�ļ���ѹ��...." << endl;;
	cout << "��ѹ��ʱ�� ";
	int begin2 = GetTickCount();
	fc.UnCompresss("1.txt");
	int end2 = GetTickCount();
	cout << end2 - begin2 << endl << endl;//��ѹ��ʱ

	//FileCompress<CharInfo> fc1;

	//cout << "Input.BIG�ļ�ѹ����...." << endl;
	//cout << "ѹ����ʱ�� ";
	//int begin3 = GetTickCount();
	//fc1.Compress("Input.BIG");//  
	//int end3 = GetTickCount();//  
	//cout << end3 - begin3 << endl << endl;

	//cout << "Input.BIG�ļ���ѹ��...." << endl;
	//cout << "��ѹ��ʱ�� ";
	//int begin4 = GetTickCount();
	//fc1.UnCompresss("Input.BIG");
	//int end4 = GetTickCount();
	//cout << (end4 - begin4) << endl;

	//FileCompress<CharInfo> fc2;
	//cout << "�����ֵ�.txt�ļ�ѹ����...." << endl;
	//cout << "ѹ����ʱ�� ";
	//int begin5 = GetTickCount();//��¼��ʼʱ��
	//fc2.Compress("�����ֵ�.txt");//  
	//int end5 = GetTickCount();//  ��¼����ʱ��
	//cout << end5 - begin5 << endl << endl;//ѹ��ʱ��

	//cout << "�����ֵ�.txt�ļ���ѹ��...." << endl;;
	//cout << "��ѹ��ʱ�� ";
	//int begin6 = GetTickCount();
	//fc2.UnCompresss("�����ֵ�.txt");
	//int end6 = GetTickCount();
	//cout << end6 - begin6 << endl << endl;//��ѹ��ʱ
}
//void TestFileCompressAgain()//����ѹ��
//{
//	cout << "����ѹ��" << endl;
//	FileCompress<CharInfo> fc;
//	cout << "Input.txt.compress�ļ�ѹ����...." << endl;
//	cout << "ѹ����ʱ�� ";
//	int begin1 = GetTickCount();//��¼��ʼʱ��
//	fc.Compress("Input.txt.compress");//  
//	int end1 = GetTickCount();//  ��¼����ʱ��
//	cout << end1 - begin1 << endl << endl;//ѹ��ʱ��
//
//	cout << "Input.txt.compress�ļ���ѹ��...." << endl;;
//	cout << "��ѹ��ʱ�� ";
//	int begin2 = GetTickCount();
//	fc.UnCompresss("Input.txt.compress");
//	int end2 = GetTickCount();
//	cout << end2 - begin2 << endl << endl;//��ѹ��ʱ
//
//	FileCompress<CharInfo> fc1;
//	cout << "Input.BIG.compress�ļ�ѹ����...." << endl;
//	cout << "ѹ����ʱ�� ";
//	int begin3 = GetTickCount();//��¼��ʼʱ��
//	fc1.Compress("Input.BIG.compress");//  
//	int end3 = GetTickCount();//  ��¼����ʱ��
//	cout << end3 - begin3 << endl << endl;//ѹ��ʱ��
//
//	cout << "Input.BIG.compress�ļ���ѹ��...." << endl;;
//	cout << "��ѹ��ʱ�� ";
//	int begin4 = GetTickCount();
//	fc1.UnCompresss("Input.BIG.compress");
//	int end4 = GetTickCount();
//	cout << end4 - begin4 << endl << endl;//��ѹ��ʱ
//
//
//
//}
//void TestFileCompressThree()
//{
//	cout << "����ѹ��" << endl;
//	FileCompress<CharInfo> fc;
//	cout << "Input.BIG.compress.compress�ļ�ѹ����...." << endl;
//	cout << "ѹ����ʱ�� ";
//	int begin5 = GetTickCount();//��¼��ʼʱ��
//	fc.Compress("Input.BIG.compress.compress");//  
//	int end5 = GetTickCount();//  ��¼����ʱ��
//	cout << end5 - begin5 << endl << endl;//ѹ��ʱ��
//
//	cout << "Input.BIG.compress.compress�ļ���ѹ��...." << endl;;
//	cout << "��ѹ��ʱ�� ";
//	int begin6 = GetTickCount();
//	fc.UnCompresss("Input.BIG.compress.compress");
//	int end6 = GetTickCount();
//	cout << end6 - begin6 << endl << endl;//��ѹ��ʱ
//}
//
//void TestFileCompressFour()
//{
//	cout << "�Ĵ�ѹ��" << endl;
//	FileCompress<CharInfo> fc;
//	cout << "Input.BIG.compress.compress.compress�ļ�ѹ����...." << endl;
//	cout << "ѹ����ʱ�� ";
//	int begin5 = GetTickCount();//��¼��ʼʱ��
//	fc.Compress("Input.BIG.compress.compress.compress");//  
//	int end5 = GetTickCount();//  ��¼����ʱ��
//	cout << end5 - begin5 << endl << endl;//ѹ��ʱ��
//
//	cout << "Input.BIG.compress.compress.compress�ļ���ѹ��...." << endl;;
//	cout << "��ѹ��ʱ�� ";
//	int begin6 = GetTickCount();
//	fc.UnCompresss("Input.BIG.compress.compress.compress");
//	int end6 = GetTickCount();
//	cout << end6 - begin6 << endl << endl;//��ѹ��ʱ
//}
//void TestFileCompressFive()
//{
//	cout << "���ѹ��" << endl;
//	FileCompress<CharInfo> fc;
//	cout << "Input.BIG.compress.compress.compress.compress�ļ�ѹ����...." << endl;
//	cout << "ѹ����ʱ�� ";
//	int begin5 = GetTickCount();//��¼��ʼʱ��
//	fc.Compress("Input.BIG.compress.compress.compress.compress");//  
//	int end5 = GetTickCount();//  ��¼����ʱ��
//	cout << end5 - begin5 << endl << endl;//ѹ��ʱ��
//
//	cout << "Input.BIG.compress.compress.compress.compress�ļ���ѹ��...." << endl;;
//	cout << "��ѹ��ʱ�� ";
//	int begin6 = GetTickCount();
//	fc.UnCompresss("Input.BIG.compress.compress.compress.compress");
//	int end6 = GetTickCount();
//	cout << end6 - begin6 << endl << endl;//��ѹ��ʱ
//}
void TestFileCompressPhoto()
{
	cout << "ͼƬѹ��" << endl;
	FileCompress<CharInfo> fc;
	cout << "��׽.PNG�ļ�ѹ����...." << endl;
	cout << "ѹ����ʱ�� ";
	int begin5 = GetTickCount();//��¼��ʼʱ��
	fc.Compress("����.PNG");//  
	int end5 = GetTickCount();//  ��¼����ʱ��
	cout << end5 - begin5 << endl << endl;//ѹ��ʱ��

	cout << "166.jpg�ļ���ѹ��...." << endl;;
	cout << "��ѹ��ʱ�� ";
	int begin6 = GetTickCount();
	fc.UnCompresss("����.PNG");
	int end6 = GetTickCount();
	cout << end6 - begin6 << endl << endl;//��ѹ��ʱ

}
//void TestFileCompressVadio()
//{
//	cout << "��Ƶѹ��" << endl;
//	FileCompress<CharInfo> fc;
//	cout << "��ɽ��_hd.mp4�ļ�ѹ����...." << endl;
//	cout << "ѹ����ʱ�� ";
//	int begin5 = GetTickCount();//��¼��ʼʱ��
//	fc.Compress("��ɽ��_hd.mp4");//  
//	int end5 = GetTickCount();//  ��¼����ʱ��
//	cout << end5 - begin5 << endl << endl;//ѹ��ʱ��
//
//	cout << "��ɽ��_hd.mp4�ļ���ѹ��...." << endl;;
//	cout << "��ѹ��ʱ�� ";
//	int begin6 = GetTickCount();
//	fc.UnCompresss("��ɽ��_hd.mp4");
//	int end6 = GetTickCount();
//	cout << end6 - begin6 << endl << endl;//��ѹ��ʱ
//}