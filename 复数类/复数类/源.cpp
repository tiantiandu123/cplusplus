//复数类：
#include<iostream>
using namespace std;
class Complex
{
public:
	Complex()
	{}
	Complex(double real, double Image)
		:_real(real)
		, _Image(Image)
	{}
	Complex(const Complex&c)
		:_real(c._real)
		, _Image(c._Image)
	{}
	Complex&operator=(const Complex&c)
	{
		if (this != &c)
		{
			_real = c._real;
			_Image = c._Image;
		}
		return *this;
	}
	Complex&operator+=(const Complex&c)
	{
		_real += c._real;
		_Image += c._Image;
		return *this;
	}
	Complex&operator-=(const Complex&c)
	{
		_real -= c._real;
		_Image -= c._Image;
		return *this;
	}
	Complex operator+(const Complex&c)
	{
		Complex tmp;
		tmp._real = _real + c._real;
		tmp._Image = _Image + c._Image;
		return tmp;
	}
	Complex operator-(const Complex&c)
	{
		Complex tmp;
		tmp._real = _real - c._real;
		tmp._Image = _Image - c._Image;
		return tmp;
	}
	Complex operator*(const Complex&c)
	{
		Complex tmp;
		tmp._real = _real *c._real;
		tmp._Image = _Image * c._Image;
		return tmp;
	}
	Complex operator/(const Complex&c)
	{
		Complex tmp;
		tmp._real = _real / c._real;
		tmp._Image = _Image / c._Image;
		return tmp;
	}
	bool operator==(const Complex&c)
	{
		return _real == c._real&&_Image == c._Image;
	}
	bool operator!=(const Complex&c)
	{
		return _real != c._real || _Image != c._Image;
	}
	bool operator>(const Complex&c)
	{
		if (this->_Image != 0 || c._Image != 0)
		{
			cout << "无法比较       ";
			return false;
		}

		else
		{
			return this->_real >c._real;
		}
	}
	bool operator>=(const Complex&c)
	{
		if (this->_Image != 0 || c._Image != 0)
		{
			cout << "无法比较       ";
			return false;
		}

		else
		{
			return this->_real >= c._real;
		}

	}
	Complex&operator++()
	{
		_real += 1;
		return *this;
	}
	Complex operator++(int)
	{
		Complex tmp(*this);
		_real += 1;
		return tmp;
	}
	void Display()const                //打印复数
	{
		cout << "_real:" << _real;
		cout << "      _image:" << _Image << endl;
	}

private:
	double _real;
	double _Image;
};
int main()
{
	Complex d1(2, 2);
	Complex d2(4.0, 6.6);
	++d1;
	d1.Display();
	d2.Display();
	//d1 = d2;
	//d1.Display();
	Complex d3;
	d3 = d1 + d2;
	cout << d1.operator==(d2) << endl;
	cout << d1.operator!=(d2) << endl;
	d3.Display();
	system("pause");
	return 0;
}