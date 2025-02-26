#include <iostream>
using namespace std;

class Procesor {
    public:
    string nazwaprocesora;
    int taktowanieprocesora;

    Procesor() {
        cout << endl << "To jest konstuktor domyslny clasy Procesor!" << endl;
        nazwaprocesora = "";
        taktowanieprocesora = 0;}

    Procesor(string _nazwaprocesora, int _taktowanieprocesora) {
        cout << endl << "To jest konstruktor 1 z argumentami clasy Procesor!" << endl;
        nazwaprocesora = _nazwaprocesora;
        taktowanieprocesora = _taktowanieprocesora;}
    
    Procesor(string _nazwaprocesora) {
        cout << endl << "To jest konstruktor 2 z argumentami clasy Procesor!" << endl;
        nazwaprocesora = _nazwaprocesora;}

    int PodajTaktowanie() {
        return taktowanieprocesora;}

    void DokonajObliczen() {
        cout << "Taktowanie procesora w Hz wynosi: " << taktowanieprocesora * 1000000000 << endl;}
};

class KartaGraficzna {
    public:
    string nazwakarty;
    int pamieckarty;

    KartaGraficzna() {
        cout << endl << "To jest konstuktor domyslny clasy KartaGraficzna!" << endl;
        nazwakarty = "";
        pamieckarty = 0;}

    KartaGraficzna(string _nazwakarty, int _pamieckarty = 8) {
        cout << endl << "To jest konstruktor 1 z argumentami clasy KartaGraficzna!" << endl;
        nazwakarty = _nazwakarty;
        pamieckarty = _pamieckarty;}

    int PodajPamiecKarty() {
        return pamieckarty;}

    void ZmienKarte(string &nazwakarty, int pamieckarty) {
        this->nazwakarty = nazwakarty;
        this->pamieckarty = pamieckarty;
        cout << endl << "Karta graficzna jest zmieniona na: " << this->nazwakarty << ", " << this->pamieckarty << endl;}
};

class PamiecRAM {
    public:
    string typpamieciram;
    int pamiec;

    PamiecRAM() {
        cout << endl << "To jest konstruktor domyslny clasy PamiecRAM!" << endl;
        typpamieciram = "";
        pamiec = 0;}

    PamiecRAM(string _typpamieciram, int _pamiec) {
        cout << endl << "To jest konstruktor 1 z argumentami clasy PamiecRAM!" << endl;
        typpamieciram = _typpamieciram;
        pamiec = _pamiec;}

    PamiecRAM(string _typpamieciram) {
        cout << endl << "To jest konstruktor 2 z argumentami clasy PamiecRAM!" << endl;
        typpamieciram = _typpamieciram;}

    void OdczytZPamieci() {
        cout << "Odczyt danych z " << typpamieciram << " nr" << this << endl;}

    void ZapisDoPamieci() {
        cout << "Zapis danych do " << typpamieciram << " nr" << this << endl;}
};

class DyskTwardy {
    public:
    string nazwadysku;
    int pojemnosc;

    DyskTwardy() {
        cout << endl << "To jest konstruktor domyslny clasy DyskTwardy" << endl;
        nazwadysku = "";
        pojemnosc = 0;}

    DyskTwardy(string _nazwadysku, int _pojemnosc) {
        cout << endl << "To jest konstruktor 1 z argumentami clasy DyskTwardy" << endl;
        nazwadysku = _nazwadysku;
        pojemnosc = _pojemnosc;}

    DyskTwardy(string _nazwadysku) {
        cout << endl << "To jest konstruktor 2 z argumentami clasy DyskTwardy" << endl;
        nazwadysku = _nazwadysku;}
};

class KontrolerUSB {
    public:
    string nazwakontrolera;
    int iloscportow;

    KontrolerUSB() {
        cout << endl << "To jest konstruktor domyslny clasy KontrolerUSB!" << endl;
        nazwakontrolera = "";
        iloscportow = 0;}

    KontrolerUSB(string _nazwakontrolera, int _iloscportow = 8) {
        cout << endl << "To jest konstruktor 1 z argumentami clasy KontrolerUSB!" << endl;
        nazwakontrolera = _nazwakontrolera;
        iloscportow = _iloscportow;}
};

class KomputerStacjonarny {
    public:
    Procesor procesor;
    KartaGraficzna kartagraficzna;
    PamiecRAM pamiecram;
    DyskTwardy dysktwardy;
    KontrolerUSB kontrolerusb;

    KomputerStacjonarny() {
        cout << endl << "To jest konstruktor domyslny clasy KomputerStacjonarny!" << endl;}

    KomputerStacjonarny(string _nazwaprocesora, string _nazwakarty, string _typpamiecram, string _nazwadysku, string _nazwakontrolera) :
     procesor(_nazwaprocesora), kartagraficzna(_nazwakarty), pamiecram(_typpamiecram), 
     dysktwardy(_nazwadysku), kontrolerusb(_nazwakontrolera) {
        cout << endl << "To jest konstruktor 1 clasy KomputerStacjonarny!" << endl;}
};

int main() {
    KomputerStacjonarny pc("Procesor 1", "Karta 8 GB", " PamiecRAM", "Dysk", "Kontroler");
}