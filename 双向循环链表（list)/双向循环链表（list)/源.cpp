#include<iostream>
using namespace std;
struct ListNode
{
	ListNode()
	:_data(0)
	,_prev(0)
	, _next(0)
	{}
	ListNode( const int data)
	:_data(data)
	, _prev(0)
	, _next(0)
	{}
	int _data;
	ListNode*_prev;
	ListNode*_next;
};
class List
{
	typedef ListNode Node;
public:
	List()
		:pHead(new Node(0))
	{
		pHead->_next = pHead;
		pHead->_prev = pHead;
	}
	List(int size, int data)
		:pHead(new Node(0))
	{
		pHead->_next = pHead;
		pHead->_prev = pHead;
		while (size--)
		{
			PushBack(data);
		}
	}
	List(const List&l)//拷贝构造函数
		:pHead(new Node)
	{
		pHead->_next = pHead;
		pHead->_prev = pHead;
		Node*cur = l.pHead->_next;
		while (cur != l.pHead)
		{
			this->PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	void PushBack(int data);//尾插
	void PopBack();//尾删
	void PushFront(int data);//头插
	void PopFront(); //头删
	void insert(Node*pos, int data);//任意位置插入
	void Erase(Node*pos);//任意位置删除
	Node* Find(int data);//寻找指定元素
	void clear();//清空
	bool Empty()const;//判断链表是否为空
	~List()
	{
		clear();
		delete pHead;
		pHead = NULL;
	}
	friend ostream&operator<<(ostream&_cout, List& l);
private:
	ListNode*pHead;
};
void List::PushBack(int data)
{
	/*Node*newNode = new Node(data);
	Node*cur = pHead->_prev;
	cur->_next = newNode;
	newNode->_prev = cur;
	newNode->_next = pHead;
	pHead->_prev = cur;*/
	Node* newNode = new Node(data);
	newNode->_prev = pHead->_prev;
	newNode->_next = pHead;
	pHead->_prev = newNode;
	newNode->_prev->_next = newNode;
}
void  List::PopBack()
{
	Node*pDel = pHead->_prev;
	pDel->_prev->_next = pHead;
	pHead->_prev = pDel->_prev;
	delete pDel;
}
void  List::PushFront(int data)
{
	Node*newNode = new Node(data);
	newNode->_next = pHead->_next;
	newNode->_prev = pHead;
	pHead->_next = newNode;
	pHead->_next->_prev = newNode;
}
void  List::PopFront()
{
	Node*delNode = pHead->_next;
	Node*pNext = pHead->_next->_next;

	delete delNode;

	pHead->_next = pNext;
	pNext->_prev = pHead;
}
void  List::insert(Node*pos, int data)
{
	Node*newNode = new Node(data);
	newNode->_next = pos;
	newNode->_prev = pos->_prev;
	pos->_prev->_next = newNode;
	pos->_prev = newNode;
}
void  List::Erase(Node*pos)
{
	Node*NextNode = pos->_next;
	Node*prevNode = pos->_prev;
	prevNode->_next = NextNode;
	NextNode->_prev = prevNode;
	delete pos;
}
ListNode*   List::Find(int data)//寻找指定元素
{
	Node*pcur = pHead;
	while (pcur->_next != pHead)
	{
		if (pcur->_data == data)
		{
			return pcur;
		}
		pcur = pcur->_next;
	}
	return NULL;
}
void  List::clear()
{
	/*Node*cur = pHead->_next;
	while (cur != pHead)
	{
	Node*temp = cur;
	cur = cur->_next;
	delete temp;
	}*/
	Node* cur = pHead->_next;
	while (cur != pHead)
	{
		Node* tmp = cur->_next;
		delete cur;
		cur = tmp;
	}

	pHead->_next = pHead;
	pHead->_prev = pHead;
}
bool  List::Empty()const//判断链表是否为空
{
	return pHead == pHead->_next;
}
ostream&operator<<(ostream&_cout, List& l)
{
	ListNode* cur = l.pHead;
	while (cur->_next != l.pHead)
	{
		_cout << cur->_data << "->";
		cur = cur->_next;
	}
	_cout << cur->_data << "->";
	_cout << "NULL";
	return _cout;
}
void test1()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	cout << "尾插" << endl;
	cout << l << endl;
	l.PushFront(6);
	l.PushFront(7);
	l.PushFront(8);
	l.PushFront(9);
	l.PushFront(10);
	cout << "头插" << endl;
	cout << l << endl;
	ListNode*pos = l.Find(2);
	cout << "查找指定位置" << endl;
	cout << l << endl;
	l.PopBack();
	cout << "尾删" << endl;
	cout << l << endl;
	l.PopFront();
	cout << "头删" << endl;
	cout << l << endl;
	cout << "指定位置删除" << endl;
	l.Erase(pos);
	cout << l << endl;
	l.clear();
}
void test2()
{
	List l1(5, 100);
	cout << l1 << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}
//#include<iostream>
//#include<list>
//using namespace std;
//
//
//template<class T>
//struct ListNode
//{
//	T _data;
//	ListNode* _next;
//	ListNode* _prev;
//	ListNode(const T& x = 0)
//		:_data(x)
//		, _next(NULL)
//		, _prev(NULL)
//	{}
//};
//
//
//template<class T, class P, class R>
//struct __ListIterator
//{
//	typedef __ListIterator<T, P, R> self;
//	typedef ListNode<T> Node;
//	Node* _it;
//
//	__ListIterator()
//	{}
//	__ListIterator(Node* node)
//		:_it(node)
//	{}
//
//	__ListIterator(const Node* node)
//		: _it(node)
//	{}
//
//	__ListIterator(const self& It)
//	{
//		_it = It._it;
//	}
//
//	~__ListIterator()
//	{
//		_it = NULL;
//	}
//	self& operator++()
//	{
//		_it = _it->_next;
//		return *this;
//	}
//	//先构造了一个tmp对象，然后返回时又调用拷贝构造，构造一个临时对象，把这个临时对象返回。然后调用析构函数析构tmp对象
//	//self operator++(int)
//	//{
//	//	self tmp(_it);
//	//	_it = _it->_next;
//	//	return tmp;
//	//}
//
//	//而这种方法不用创建临时对象。
//	self& operator++(int)
//	{
//		Node* tmp = _it;
//		_it = _it->_next;
//		return self(tmp);
//	}
//
//	self& operator--()
//	{
//		_it = _it->_prev;
//		return self(_it);
//	}
//	self& operator--(int)
//	{
//		Node* tmp = _it;
//		_it = _it->_prev;
//		return self(tmp);
//	}
//
//	R operator*() const
//	{
//		return _it->_data;
//	}
//
//	P operator->() const
//	{
//		return &(_it->_data);
//	}
//
//	bool operator==(self& It)
//	{
//		return It._it == _it;
//	}
//	bool operator!=(self& It)
//	{
//		if (_it != It._it)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};
//template<class T>
//class List
//{
//	typedef ListNode<T> Node;
//	typedef const T* ConstPtr;
//	typedef const T& ConstRef;
//	typedef T* Ptr;
//	typedef T& Ref;
//public:
//	typedef __ListIterator<T, T*, T&> Iterator;
//	typedef __ListIterator<T, const T*, const T&> ConstIterator;
//public:
//	List()
//		:_head(new Node)
//	{
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	void PushBack(const T& x)
//	{
//		Node* tmp = new Node(x);
//		tmp->_prev = _head->_prev;
//		tmp->_next = _head;
//		_head->_prev = tmp;
//		tmp->_prev->_next = tmp;
//	}
//	void PushFront(const T& x)
//	{
//		Node* tmp = new Node(x);
//
//		Node* Next = _head;
//		Node* Prev = _head->_prev;
//		_head = tmp;
//		_head->_next = Next;
//		_head->_prev = Prev;
//	}
//	void PopBack()
//	{
//		Node* Next = _head;
//		Node* Prev = _head->_prev->_prev;
//		delete _head->_prev;
//
//		Prev->_next = Next;
//		Next->_prev = Prev;
//	}
//	void PopFront()
//	{
//		Node* Next = _head->_next;
//		Node* Prev = _head->_prev;
//		delete _head;
//		_head = Next;
//		_head->_prev = Prev;
//
//		Prev->_next = _head;
//
//
//	}
//	Iterator Insert(Iterator It, const T& x)
//	{
//		Node* tmp = It._it->_prev;
//		Node* newNode = new Node(x);
//		tmp->_next = newNode;
//		newNode->_prev = tmp;
//
//		newNode->_next = It._it;
//		It._it->_prev = newNode;
//		return newNode;
//	}
//
//	Iterator Erase(Iterator It)
//	{
//		Node* tmp = It._it;
//		Node* Prev = tmp->_prev;
//		Node* Next = tmp->_next;
//
//		Prev->_next = Next;
//		Next->_prev = Prev;
//		delete tmp;
//		return Iterator(Next);
//	}
//	//下面这种办法可以在erase之后可以直接++，加到下一个数字。
//	/*Iterator Erase(Iterator It)
//	{
//	Node* tmp = It._it;
//	Node* Prev = tmp->_prev;
//	Node* Next = tmp->_next;
//
//	Prev->_next = Next;
//	Next->_prev = Prev;
//	delete tmp;
//	It = Prev;
//	return It;
//	}*/
//
//	Ref Front()
//	{
//		return *(Begin());
//	}
//	ConstRef Front() const
//	{
//		return *(Begin());
//	}
//
//	Ref Back()
//	{
//		return *(--End());
//	}
//
//	ConstRef Back()	const
//	{
//		return *(--End());
//	}
//
//	ConstIterator Begin() const
//	{
//		return ConstIterator(_head->_next);
//	}
//	ConstIterator End() const
//	{
//		return ConstIterator(_head);
//	}
//	Iterator Begin()
//	{
//		return _head->_next;
//	}
//	Iterator End()
//	{
//		return _head;
//	}
//
//
//	void Clear()
//	{
//		Node* cur = _head->_next;
//		while (cur != _head)
//		{
//			Node* tmp = cur->_next;
//			delete cur;
//			cur = tmp;
//		}
//
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//
//	~List()
//	{
//		Clear();
//		delete _head;
//		_head = NULL;
//	}
//
//private:
//	Node* _head;
//};
//
//struct AA
//{
//	int _data;
//	AA(const int& x)
//	{
//		_data = x;
//	}
//};
//
//template<class T>
//void printConstList(const List<T>& l)
//{
//	List<T>::ConstIterator it = l.Begin();
//	while (l.End() != it)
//	{
//		//*it = 10;
//		cout << *it << endl;
//		++it;
//	}
//}
//
//template<class T>
//void printList(List<T>& l)
//{
//	List<T>::Iterator it = l.Begin();
//	while (l.End() != it)
//	{
//		cout << *it << endl;
//		++it;
//	}
//}
//template<class T>
//void print(list<T>& s)
//{
//	list<T>::iterator it = s.begin();
//	cout << "正向迭代器打印:";
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//void TestList()
//{
//	List<int> l;
//	l.PushBack(1);
//	l.PushBack(2);
//	l.PushBack(3);
//	l.PushBack(4);
//
//	//使用const迭代器
//	//printConstList(l);
//
//	l.PopBack();
//	printList(l);
//	l.PopFront();
//	l.Clear();
//	printList(l);
//
//	/*List<int>::Iterator it = l.Begin();
//	while (it != l.End())
//	{
//	if (*it % 2 == 0)
//	{
//	it = l.Erase(it);
//	}
//	else
//	{
//	it++;
//	}
//	}*/
//}
//
//
//int main()
//{
//
//	TestList();
//
//	return 0;
//}