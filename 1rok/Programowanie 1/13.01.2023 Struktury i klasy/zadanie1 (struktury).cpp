#include <iostream>
using namespace std;

struct student {
char imie[25];
int algebra, programowanie, architektura, wdi;
};

int main() { 

student a[5];

for(int i=0; i < 5; i++) {
    cout << "Podaj imie studenta nr "<< i + 1 <<": ";
    cin >> a[i].imie;
    cout << "Podaj ocene z Algebry: ";
    cin >> a[i].algebra;
    cout << "Podaj ocene z Programowania: ";
    cin >> a[i].programowanie;
    cout << "Podaj ocene z Architektury komputerow: ";
    cin >> a[i].architektura;
    cout << "Podaj ocenê z Wstepu do Informatyki: ";
    cin >> a[i].wdi;
}

int n;
cout<<"Podaj liczbe zapytan: ";
cin >> n;

int nr, przedmiot;

while(n--) {
cout << "Podaj nr studenta z przedzia³u [1..5]: ";
cin >> nr;
nr--;

if (nr < 0 || nr >= 5) {
cout << "Brak indeksu!"<< endl;
continue;}

cout << "Podaj nr przedmiotu z przedzia³u [0..3]: ";
cin >> przedmiot;
if (przedmiot < 0 || przedmiot > 3) {
cout << "Brak przedmiotu!" << endl;
continue;}

switch(przedmiot) {
      case 0: cout << "Student: " << a[nr].imie << ", ocena z Algebry: " << a[nr].algebra <<endl;
break;
      case 1: cout << "Student: " << a[nr].imie << ", ocena z Programowania: " << a[nr].programowanie << endl; 
break;
      case 2: cout<< "Student: " << a[nr].imie << ", ocena z Architektury komputerow: " << a[nr].architektura << endl;
break;
      case 3: cout << "Student: " << a[nr].imie << ", ocena z Wstepu do Informatyki: " << a[nr].wdi <<endl;
break;
}}}

