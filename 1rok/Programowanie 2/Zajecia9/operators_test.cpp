#include <iostream>
using namespace std;

class IntegerTwice
{
public:
    int value;

    IntegerTwice(int _value = 0)
    {
        value = _value;
    }

    void print() const
    {
        cout << value;
    }

    int get(int index)
    {
        return value;
    }

///// Operatory:

    IntegerTwice &operator=(IntegerTwice other)
    {
        value = other.value * 2;
        return *this;
    }

    IntegerTwice &operator+=(IntegerTwice other)
    {
        value += other.value * 2;
        return *this;
    }

	IntegerTwice operator[](IntegerTwice i) const
	{
		return IntegerTwice(value * 2 * i.value);
	}

	IntegerTwice &operator++()
	{
        value = value + 1;
		return *this;
	}

	IntegerTwice operator++(int p) // bez referencji
	{
		IntegerTwice old = *this;
		// operator++();
        value = value + 1;
		return old;
	}

	void *operator new[](size_t size)
	{
		cout << size << endl;
		return malloc(size);
	}
    
    friend ostream &operator<<(ostream &os, const IntegerTwice &a);
};

ostream &operator<<(ostream &os, const IntegerTwice &a)
{
    os << "|Integer: " << a.value << "|";
    return os;
}

inline bool operator==(const IntegerTwice &lhs, const IntegerTwice &rhs) { return false; }

int main()
{
	IntegerTwice *ptr = new IntegerTwice[100];

    IntegerTwice a(10);
    IntegerTwice b(10);

    cout << (a == a);

    IntegerTwice c = a++;
    IntegerTwice d = ++b;

    a = b;
    a += b;

    // a.print();
    // cout << a.value;
    cout << a << b << endl;

    cout << a[b];
}