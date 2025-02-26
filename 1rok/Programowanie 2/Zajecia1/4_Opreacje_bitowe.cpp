#include <iostream>
using namespace std;

// Co oznacza i/=2?
// Jaka bedzie wartosc b przed samym zakonczeniem funkcji?

void wyswietlBinarnie(unsigned char b)
{
	// cout << b << endl;
	// cout << (int)b << endl;
	for (int i = 128; i > 0; i /= 2)
	{
		if (b / i)
		{
			cout << 1;
			b -= i; // Po co ta linijka?
		}
		else
		{
			cout << 0;
		}
	}
	cout << endl;
	// cout << (int)b <<endl ; //Co sie wyswietli? dlaczego?
};

int main()
{

	unsigned char b = 0x55; // 01010101
	// cout << b << endl;
	wyswietlBinarnie(b);

	unsigned char c = 0x0f; // 00001111
	wyswietlBinarnie(c);

	wyswietlBinarnie(!b);
	wyswietlBinarnie(!!b); // co to robi?
	cout << "----" << endl;
	wyswietlBinarnie(~b);
	wyswietlBinarnie(b & c);
	wyswietlBinarnie(b | c);
	wyswietlBinarnie(b << 2);
	wyswietlBinarnie(b ^ c);

	// jak szyfrowac orem, andem ? czemu xor jest fajny?

	cin.ignore();
	return 0;
}
