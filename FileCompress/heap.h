#pragma once    
#include <vector>    
#include<assert.h>    
using namespace std;
// Ð¡¶Ñ    
template<class T>
struct Less
{
	bool operator() (const T& l, const T& r)
	{
		return l < r;
	}
};
//´ó¶Ñ
template<class T>
struct Greater
{
	bool operator() (const T& l, const T& r)
	{
		return l > r;
	}
};

template<class T, class Compare = Less<T>>
class Heap
{
public:
	Heap()
	{}

	Heap(const T* a, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			_infosays.push_back(a[i]);
		}

		// ½¨¶Ñ    
		for (int i = (_infosays.size() - 2) / 2; i >= 0; --i)
		{
			AdjustDown(i);
		}
	}

	void Push(const T& x)
	{
		_infosays.push_back(x);
		AdjustUp(_infosays.size() - 1);
	}

	void Pop()
	{
		assert(_infosays.size() > 0);
		swap(_infosays[0], _infosays[_infosays.size() - 1]);
		_infosays.pop_back();

		AdjustDown(0);
	}

	const T& Top()
	{
		//assert(_infosays.size() > 0);
		if (!Empty())
		{
			return _infosays[0];
		}

	}

	bool Empty()
	{
		return _infosays.empty();
	}

	int Size()
	{
		return _infosays.size();
	}

	void AdjustDown(int root)
	{
		size_t child = root * 2 + 1;

		Compare com;
		while (child < _infosays.size())
		{
			if (child + 1<_infosays.size() &&
				com(_infosays[child + 1], _infosays[child]))
			{
				++child;
			}


			if (com(_infosays[child], _infosays[root]))
			{
				swap(_infosays[child], _infosays[root]);
				root = child;
				child = 2 * root + 1;
			}
			else
			{
				break;
			}
		}
	}

	void AdjustUp(int child)
	{
		int parent = (child - 1) / 2;


		while (child > 0)
		{
			if (Compare()(_infosays[child], _infosays[parent]))
			{
				swap(_infosays[parent], _infosays[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void Print()
	{
		for (size_t i = 0; i < _infosays.size(); ++i)
		{
			cout << _infosays[i] << " ";
		}
		cout << endl;
	}

public:
	vector<T> _infosays;
};