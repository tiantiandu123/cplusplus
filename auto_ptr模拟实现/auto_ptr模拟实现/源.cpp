//既然要控制资源的转移，我们可以多定义一个成员对象_owner来标识该成员对象的资源管理权，在调用构造函数创建对象时赋予其资源管理权，即_owner置为true，在调用拷贝构造函数、赋值运算符的时候将其管理权释放，即_owner置为false，就起到了资源管理权的转移。
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
//	T&operator*()//解引用操作符重载
//	{
//		return *(this->_ptr);
//	}
//	T&operator*()const//const型解引用操作符重载
//	{
//		return  *(this->_ptr);
//	}
//	T*operator->()//取地址操作符重载
//	{
//		return this->_ptr;
//	}
//	T*operator->()const//const型取地址操作符重载
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
//	mutable bool _symbol;//在const修饰的成员函数中要对类的某个数据成员进行修改，该数据成员定义声明必须加mutale关键字。
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

//新版
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
	T&operator*()//解引用操作
	{
		return *(this->_ptr);
	}
	T&operator*()const//解引用操作
	{
		return *(this->_ptr);
	}
	T*operator->()//取地址操作
	{
		return this->_ptr;
	}
	T*operator->()const//const取地址操作
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
//template<class T>//构造函数
//AutoPtr<T>::AutoPtr()
//:_ptr(NULL)
//{}
//template<class T>
//AutoPtr<T>::AutoPtr(T* ptr) // 不能写成const T* ptr，const类型的赋值不能给非const类型
//: _ptr(ptr)
//{}
//template<class T>//拷贝构造
//AutoPtr<T>::AutoPtr(AutoPtr<T>& ap)
//: _ptr(ap._ptr)
//{
//	ap._ptr = NULL;
//}
//
//template<class T>//赋值运算符的重载
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
//template<class T>//析构函数
//AutoPtr<T>::~AutoPtr()
//{
//	if (this->_ptr)
//	{
//		delete this->_ptr;
//		this->_ptr = NULL;
//	}
//}
//
//template<class T>//重载*
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
//template<class T>//重载->
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

