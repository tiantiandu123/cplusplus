//��ȻҪ������Դ��ת�ƣ����ǿ��Զඨ��һ����Ա����_owner����ʶ�ó�Ա�������Դ����Ȩ���ڵ��ù��캯����������ʱ��������Դ����Ȩ����_owner��Ϊtrue���ڵ��ÿ������캯������ֵ�������ʱ�������Ȩ�ͷţ���_owner��Ϊfalse����������Դ����Ȩ��ת�ơ�
#include<iostream>
using namespace std;
//template<class T>
//class Autoptr
//{
//public:
//	Autoptr<T>(T*ptr = NULL)
//		:_ptr(ptr)
//		, _symbol(true)
//
//	{}
//	Autoptr<T>(const Autoptr<T>&a)
//		:_ptr(a._ptr)
//		, _symbol(true)
//	{
//		a._symbol = false;
//	}
//	Autoptr<T>&operator=(const Autoptr<T>&a)
//	{
//		if (this != &a)
//		{
//			delete this->_ptr;
//			_ptr = a._ptr;
//			_symbol = ture;
//			a._symbol = false;
//		}
//		return *this;
//	}
//	T&operator*()//�����ò���������
//	{
//		return *(this->_ptr);
//	}
//	T&operator*()const//const�ͽ����ò���������
//	{
//		return  *(this->_ptr);
//	}
//	T*operator->()//ȡ��ַ����������
//	{
//		return this->_ptr;
//	}
//	T*operator->()const//const��ȡ��ַ����������
//	{
//		return this->_ptr;
//	}
//	~Autoptr<T>()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = NULL;
//			_symbol = false;
//		}
//	}
//private:
//	T* _ptr;
//	mutable bool _symbol;//��const���εĳ�Ա������Ҫ�����ĳ�����ݳ�Ա�����޸ģ������ݳ�Ա�������������mutale�ؼ��֡�
//};
//int main()
//{
//	Autoptr<int>p1(new int);//
//	int i = 1;
//	if (i == 1)
//	{
//		Autoptr<int>p2(p1);
//	}
//	*p1 = 10;
//	system("pause");
//	return 0;
//}

//�°�
template<class T>
class Auto_ptr
{
public:
	Auto_ptr(T*ptr=NULL)
		: _ptr(ptr)
	{}
	Auto_ptr( Auto_ptr<T>&a)
		:_ptr(a._ptr)
	{
		a._ptr = NULL;
	}
	Auto_ptr<T>&operator=( Auto_ptr<T>&a)
	{
		if (this != &a)
		{
			delete _ptr;
			_ptr = a._ptr;
			a._ptr = NULL;
		}
		return *this;
	}
	T&operator*()//�����ò���
	{
		return *(this->_ptr);
	}
	T&operator*()const//�����ò���
	{
		return *(this->_ptr);
	}
	T*operator->()//ȡ��ַ����
	{
		return this->_ptr;
	}
	T*operator->()const//constȡ��ַ����
	{
		return this->_ptr;
	}
	~Auto_ptr<T>()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}
private:
	T* _ptr;
};
Auto_ptr<int> FunTest()
{
	Auto_ptr<int> p(new int(1));
	return p;
}
int main()
{
		Auto_ptr<int> ap1(FunTest());
	//Auto_ptr<int> p(new int(1));
	//Auto_ptr<int> p1(p);
	//Auto_ptr<int> p2 = p1;
	//*p1= 10;
	system("pause");
	return 0;
}
//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr();
//	AutoPtr(T* ptr);
//	AutoPtr(AutoPtr<T>& ap);
//	AutoPtr<T>& operator=(AutoPtr<T>& ap);
//	~AutoPtr();
//	T& operator*();
//	T& operator*()const;
//	T* operator->();
//	T* operator->()const;
//protected:
//	T* _ptr;
//};
//
//template<class T>//���캯��
//AutoPtr<T>::AutoPtr()
//:_ptr(NULL)
//{}
//template<class T>
//AutoPtr<T>::AutoPtr(T* ptr) // ����д��const T* ptr��const���͵ĸ�ֵ���ܸ���const����
//: _ptr(ptr)
//{}
//template<class T>//��������
//AutoPtr<T>::AutoPtr(AutoPtr<T>& ap)
//: _ptr(ap._ptr)
//{
//	ap._ptr = NULL;
//}
//
//template<class T>//��ֵ�����������
//AutoPtr<T>& AutoPtr<T>::operator=(AutoPtr<T>& ap)
//{
//	if (this != &ap)
//	{
//		delete this->_ptr;
//		this->_ptr = ap._ptr;
//		ap._ptr = NULL;
//	}
//	return *this;
//}
//template<class T>//��������
//AutoPtr<T>::~AutoPtr()
//{
//	if (this->_ptr)
//	{
//		delete this->_ptr;
//		this->_ptr = NULL;
//	}
//}
//
//template<class T>//����*
//T& AutoPtr<T>::operator*()
//{
//	return *(this->_ptr);
//}
//template<class T>
//T& AutoPtr<T>::operator*()const
//{
//	return *(this->_ptr);
//}
//
//template<class T>//����->
//T* AutoPtr<T>::operator->()
//{
//	return this->_ptr;
//}
//template<class T>
//T* AutoPtr<T>::operator->()const
//{
//	return this->_ptr;
//}
//
//
//
//int main()
//{
//	AutoPtr<int> p(new int(1));
//	AutoPtr<int> p1(p);
//	AutoPtr<int> p2 = p1;
//	*p1 = 10;
//	system("pause");
//	return 0;
//}

