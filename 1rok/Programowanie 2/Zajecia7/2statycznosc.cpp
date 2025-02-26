#include <iostream>
using namespace std;

class S
{
	int a;
	static int counter;

public:
	S() : a(1) { counter++; }

	// void setCounter(int _counter) { counter = _counter; }
	// void setA(int _a) { a = _a; }
	// void print() { cout << a << " " << counter << endl; }

	// static void changeCounter(int _counter)
	// {
	// 	counter = _counter;
	// }
};

int S::counter = 0;

int main()
{

	// S::changeCounter(90);

	S s1, s2, s3;

	// s1.print();
	// s2.print();

	// s2.setA(15);
	// s2.print();

	// s1.setCounter(50);

	// s2.print();

	// cin.ignore();
	return 0;
}
