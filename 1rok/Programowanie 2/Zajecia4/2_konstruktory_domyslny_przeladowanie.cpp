#include <iostream>
#include <string>
using namespace std;


class Samochod {
	string marka;
	string model;
	unsigned przebieg;

public:
	Samochod() {
		cout << "Konstruktor domyslny klasy Samochod" << endl;
		(*this).marka = "";
		model = "";
		przebieg = 0;
	}
	
	Samochod(string _marka, string _model, unsigned _przebieg) {
		cout << "Konstruktor 1 z argumentami klasy Samochod" << endl;
		marka = _marka,
		model = _model;
		przebieg = _przebieg;
	}

	Samochod(string _marka, string _model) {
		cout << "Konstruktor 2 z argumentami klasy Samochod" << endl;
		marka = _marka,
		model = _model;
		przebieg = 0;
	}
	
	void prezentuj() const {
		cout << this->marka << " " << model << " " << przebieg << endl;
	} 

	void jedz(unsigned x) {
		cout << marka << " " << model << " jedzie" << endl;
		przebieg += x;
	}


};

int main() {

	Samochod s1;
	s1.prezentuj();
	
	Samochod s2("Opel", "Corsa", 80);
	s2.prezentuj();
	
		
//	Samochod& s = s1;
//	s = s2;

	 

//	s1.jedz(50);
//	s1.prezentuj();
	//s2.prezentuj();

	//cin.get();
	//cin.ignore();
	return 0;

}
