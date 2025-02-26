#include <iostream>
#include <string>
#include <string.h>
using namespace std;

unsigned char zakoduj(string napis) {
    char result = 0;
    for (int i = 0; i < 8; i++) {
            result |= (napis[i] - '0') << (7 - i);} //'0' w ascii = 48
    return result;
}

string odkoduj(unsigned char n) {
    string result = "";
    for (int i = 7; i >= 0; i--) {
        result += ((n >> i) & 1) ? '1' : '0';}
    return result;
}

unsigned char zaszyfruj(unsigned char tekst, unsigned char klucz) {
    unsigned char result = (tekst & ~klucz) | (~tekst & klucz);
    return result;
}

unsigned char odszyfruj(unsigned char kod, unsigned char klucz) { // nie jest potrzebna 
    zaszyfruj(kod, klucz);
}

string zaszyfruj(string tekst, string klucz) {
    string result = "";
    for (int i = 0; i < tekst.size(); i++) {
        if ((tekst[i] == '0' && klucz[i] == '0') || (tekst[i] == '1' && klucz[i] == '1')) result += '0';
        else result += '1';
    }
    return result;
}

string odszyfruj(string kod, string klucz) {
    return zaszyfruj(kod, klucz);
}

unsigned char zaszyfruj2(unsigned char kod, unsigned char klucz) {
    klucz <<= 1;
    klucz |= 1;
    unsigned char result = ~(kod ^ klucz);
    return result;
}

unsigned char odszyfruj2(unsigned char kod, unsigned char klucz) {
    return zaszyfruj2(kod, klucz);
}

string przeczytaj(string tekst) {
    string result = "";
    for (int i = 0; i < tekst.size(); i++) {
        if (tekst[i] == '1') result += "jeden ";
        else result += "zero ";
    }
    return result;
}
/*
int main(int argc, char* argv[]) {
    string tekst  = argv[1];
    string klucz = argv[2];
    cout << odszyfruj(zaszyfruj(tekst, klucz), klucz) << endl;
}
*/

int main() {
    string napis = "10100010";
    char result = zakoduj(napis);
    cout << napis << " " << result << endl;

    char n = 'j';
    string kod = odkoduj(n);
    cout << n << " " << kod << endl;

    unsigned char tekst1 = '0';
    unsigned char klucz1 = '1';
    unsigned char szyfr = zaszyfruj(tekst1, klucz1);
    cout << tekst1 << " " << szyfr << endl;

    unsigned char tekst2 = '0';
    unsigned char klucz2 = '1';
    unsigned char odszyfr = odszyfruj(klucz2, tekst2);
    cout << tekst2 << " " << odszyfr << endl;

    string tekst3 = "10110001";
    string klucz3 = "10010001";
    string zaszyfr = zaszyfruj(tekst3, klucz3);
    cout << tekst3 << " " << zaszyfr << endl;

    string tekst4 = "10110001";
    string klucz4 = "10011001";
    string od = odszyfruj(tekst4, klucz4);
    cout << tekst4 << " " << od << endl;

    unsigned char tekst5 = '1011';
    unsigned char klucz5 = '1111';
    cout << zaszyfruj2(tekst5, klucz5) << endl;

    string tekst6 = "100101001";
    cout << przeczytaj(tekst6) << endl;

    return 0;
}


