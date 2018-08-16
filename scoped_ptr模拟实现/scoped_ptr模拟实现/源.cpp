#include<iostream>
using namespace std;
template<class T>
class ScopedPtr
{
public:
	ScopedPtr(T*ptr)
		:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}
	T&operator*()
	{
		return *(this->_ptr);
	}
	 T&operator*()const
	{
		 return *(this->_ptr);
	}
	 T*operator->()
	 {
		 return this->_ptr;
	 }
	 T*operator->()const
	 {
		 return this->_ptr;
	 }
private:
	ScopedPtr(const ScopedPtr&s);
	ScopedPtr<T>&operator=(const ScopedPtr&s);
	T* _ptr;
};
int main()
{
	ScopedPtr<int> p1(new int(3));
	system("pause");
	return 0;
}
