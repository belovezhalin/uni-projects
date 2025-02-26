#include <iostream>

using namespace std;

class Tablica {
	double* elementy;
	unsigned liczbaElementow;

public:
	Tablica(unsigned l = 1) : liczbaElementow(l) {
		elementy = new double[liczbaElementow];
		for (unsigned i = 0; i < liczbaElementow; ++i) {
			elementy[i] = 0;
		}
		cout << "Konstruktor tablicy" << endl;
	}
	
	Tablica(const Tablica& t) { // const - b�dzie w przysz�o�ci
		liczbaElementow = t.liczbaElementow;
		elementy = new double[liczbaElementow];
		for (unsigned i = 0; i < liczbaElementow; ++i) {
			elementy[i] = t.elementy[i];
		}
		cout << "Konstruktor kopiujacy tablicy" << endl;
	}

	~Tablica() {
		delete[] elementy;
		elementy = 0;
		cout << "Destruktor tablicy" << endl;
	}


	Tablica& operator=(const Tablica& t) {
		if (this == &t) return *this;

		liczbaElementow = t.liczbaElementow;
		if (elementy) {
			delete[] elementy;
			elementy = NULL;
		}
		elementy = new double[liczbaElementow];
		for (unsigned i = 0; i < liczbaElementow; ++i) {
			elementy[i] = t.elementy[i];
		}
		cout << "Operator przypisania tablicy" << endl;
		return *this;
	}
	
	
	
	void zeruj() {
		delete[] elementy;
		liczbaElementow = 1;
		elementy = new double[1];
		elementy[0] = 0;
	}

	void wstaw(unsigned miejsce, double element) {
		if (miejsce > liczbaElementow - 1) { //kontrola - pola private
			cout << "Tablica jest za ma�a";
			return;
		}
		elementy[miejsce] = element;
	}

	void prezentuj() const {
		cout << "Prezentacja tablicy" << endl;
		for (unsigned i = 0; i < liczbaElementow; i++) {
			cout << elementy[i] << endl;
		}
		cout << endl;
	}
};




int main() {
	
	Tablica T1(3);
	T1.wstaw(0, 10.);
	T1.wstaw(1, 20.);
	T1.wstaw(2, 30.);
	T1.prezentuj();

	Tablica T2, T3;

	Tablica T4(T1);
	T3.prezentuj();

	T2.prezentuj();
	T2 = T1;
	T2.prezentuj();

	//T3 = T2 = T1;
	T1.zeruj();
	
	T3.prezentuj();
	
	







/*What happens when we write only a copy constructor � does compiler create default constructor?
Compiler doesn�t create a default constructor if we write any constructor even if it is copy constructor. 


What about reverse � what happens when we write a normal constructor and don�t write a copy constructor?
Reverse is not true. Compiler creates a copy constructor if we don�t write our own. 
Compiler creates it even if we have written other constructors in class.
*/

	return 0;

}


