#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;

struct mleczarnia {
	unsigned int indeks;
	string rejon;
	string nazwisko;
	string imie;
	string data_urodzenia;
	int litry;
	float tluszcz;
	string klasa_mleka;
};

int main(){
setlocale(LC_ALL, "");
srand(time(NULL));

mleczarnia osoba[10];
osoba[0] = {1, "Bielawa", "Kalisz", "Eugenia", "1972-12-18", 155, 4.1, "I"};
osoba[1] = {83, "Olszyna", "Gora", "Lucyna", "1971-09-13", 158, 3.7, "II"};
osoba[2] = {208, "Strzelin", "Hudzik", "Anna", "1977-01-05", 149, 3.7, "E"};
osoba[3] = {270, "Czernicha", "Las", "Maria", "1976-04-14", 189, 3.8, "P"};
osoba[4] = {381, "Brodnica", "Janas", "Jan", "1976-10-15", 562, 3.6, "II"};
osoba[5] = {415, "Koronowo", "Knapik", "Jan", "1973-08-05", 323, 3.8, "E"};
osoba[6] = {457, "Lipno", "Dynda", "Henryk", "1974-08-22", 266, 3.7, "I"};
osoba[7] = {515, "Radomin", "Wojna", "Jacek", "1971-09-03", 108, 3.6, "I"};
osoba[8] = {636, "Pruszcz", "Mika", "Zofia", "1973-07-13", 125, 3.8, "I"};

cout << "Wprowadz indeks: ";
cin >> osoba[9].indeks;
cout << "Wprowadz rejon: ";
cin >> osoba[9].rejon;
cout << "Wprowadz nazwisko: ";
cin >> osoba[9].nazwisko;
cout << "Wprowadz imie: ";
cin >> osoba[9].imie;
cout << "Wprowadz data_urodzenia: ";
cin >> osoba[9].data_urodzenia;
cout << "Wprowadz litry: ";
cin >> osoba[9].litry;
cout << "Wprowadz tluszcz: ";
cin >> osoba[9].tluszcz;
cout << "Wprowadz klase mleka: ";
cin >> osoba[9].klasa_mleka;

for (int i=0; i < 10; i++) {
	cout.width(10);
	cout << osoba[i].nazwisko;
	cout.width(10);
	cout << osoba[i].imie;
	cout.width(5);
	cout << osoba[i].litry << endl;}

int suma = 0;
for (int i = 0; i < 10; i++) {
	suma += osoba[i].litry;}
cout << "Suma litrow mleka: " << suma << endl;
	
double srednia = 0;
for (int i = 0; i < 10; i++) {
	srednia += osoba[i].tluszcz;}
srednia = srednia / 10; 
cout << "Srednia zawartosc tluszczu: " << srednia << endl;

double lit = 0;
double sum = 0;
for (int i = 0; i < 10; i++) {
lit = lit + osoba[i].litry;
sum = sum + osoba[i].litry * osoba[i].tluszcz;}
double waz = sum / lit;
cout << "Srednia wazona tluszczu: " << waz << endl;

cout << "WYPLATA" << endl;
for (int i = 0; i < 10; i++) {
double L = osoba[i].litry;
double dop0 = L * 1.15;
double dop1 = 0;
if (L > 150) dop1 = L*0.5;
double dop2 = 0;
if (osoba[i].tluszcz < 3.8) dop2 = L*0.4;
double dop3 = 0;
if (osoba[i].klasa_mleka == "E" || osoba[i].klasa_mleka == "I") dop3 = L * 0.3;
double wyp = dop0 + dop1 + dop2 + dop3;
cout.width(10);
cout << osoba[i].nazwisko;
cout.width(10);
cout << osoba[i].imie;
cout << fixed << setprecision(2);
cout.width(10);
cout << wyp << endl;}

ofstream Po("zadanie.txt");
for (int i = 0; i < 10; i++) {
Po << osoba[i].indeks << " ";
Po << osoba[i].rejon << " ";
Po << osoba[i].nazwisko << " ";
Po << osoba[i].imie << " ";
Po << osoba[i].data_urodzenia << " ";
Po << osoba[i].litry << " ";
Po << osoba[i].tluszcz << " ";
Po << osoba[i].klasa_mleka << endl;}
Po.close();
ifstream Pi("zadanie.txt");
string w;
while (!Pi.eof()){
getline(Pi, w);
cout << w << endl;}
Pi.close();

cout << "WRZESIEN" << endl;
for (int i = 0; i < 10; i++) {
string ur = osoba[i].data_urodzenia;
string mi = ur.substr(5,2);
if (mi == "09") cout << mi << " " << osoba[i].nazwisko << " " << osoba[i].imie << endl;}

cout << "PLEC-MLEKO" << endl;
int liM = 0;
int liK = 0;
for (int i = 0; i < 10; i++) {
string im = osoba[i].imie;
int dl = im.length();
if (im[dl-1] == 'a') liK = liK + osoba[i].litry;
else liM = liM + osoba[i].litry;}
cout << "M " << liM << endl;
cout << "K " << liK << endl;
system("pause");
}
