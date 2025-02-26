#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum class Odpowiedz
{
    TRUE_POSITIVE,
    FALSE_POSITIVE,
    TRUE_NEGATIVE,
    FALSE_NEGATIVE
};

class Pytanie
{
public:
    vector<Odpowiedz> odpowiedzi;
    Pytanie() {}

    void UstawOdpowiedzi(const vector<Odpowiedz> &odpowiedzi_)
    {
        odpowiedzi = odpowiedzi_;
    }

    int LiczbaPrawidlowychOdpowiedzi() const
    {
        int count = 0;
        for (int i = 0; i < odpowiedzi.size(); i++)
        {
            if (odpowiedzi[i] == Odpowiedz::TRUE_POSITIVE || odpowiedzi[i] == Odpowiedz::TRUE_NEGATIVE)
            {
                count++;
            }
        }
        return count;
    }

    int LiczbaNieprawidlowychOdpowiedzi() const
    {
        int count = 0;
        for (int i = 0; i < odpowiedzi.size(); i++)
        {
            if (odpowiedzi[i] == Odpowiedz::FALSE_POSITIVE || odpowiedzi[i] == Odpowiedz::FALSE_NEGATIVE)
            {
                count++;
            }
        }
        return count;
    }
};

class Oceniacz
{
public:
    virtual float Ocen(const Pytanie &pytanie) const = 0;
    virtual ~Oceniacz() {}
};

class Oceniacz1 : public Oceniacz
{
public:
    float Ocen(const Pytanie &pytanie) const
    {
        if (pytanie.LiczbaPrawidlowychOdpowiedzi() == pytanie.LiczbaNieprawidlowychOdpowiedzi())
        {
            return 1.0;
        }
        else
        {
            return 0.0;
        }
    }
};

class Oceniacz2 : public Oceniacz
{
public:
    float Ocen(const Pytanie &pytanie) const
    {
        if (pytanie.LiczbaPrawidlowychOdpowiedzi() > 0 && pytanie.LiczbaNieprawidlowychOdpowiedzi() == 0)
        {
            return 1.0;
        }
        else
        {
            return -1.0;
        }
    }
};

class Oceniacz3 : public Oceniacz
{
public:
    float Ocen(const Pytanie &pytanie) const
    {
        int totalOdpowiedzi = pytanie.LiczbaPrawidlowychOdpowiedzi() + pytanie.LiczbaNieprawidlowychOdpowiedzi();
        if (totalOdpowiedzi == 0)
        {
            return 0.0;
        }
        else
        {
            float punkty = float(pytanie.LiczbaPrawidlowychOdpowiedzi()) / totalOdpowiedzi;
            return punkty;
        }
    }
};

class Student
{
public:
    string imie;
    string nazwisko;

    Student(const string &i, const string &n) : imie(i), nazwisko(n) {}

    string getImie() const
    {
        return imie;
    }

    string getNazwisko() const
    {
        return nazwisko;
    }
};

class Test
{
public:
    int liczbaPytan;
    Student student;
    Pytanie pytanie;
    vector<Pytanie> pytania;

    Test(int lp, const Student &s) : liczbaPytan(lp), student(s) {}

    int getLiczbaPytan() const
    {
        return liczbaPytan;
    }

    const Student &getStudent() const
    {
        return student;
    }

    void dodajPytanie(const Pytanie &pytanie)
    {
        pytania.push_back(pytanie);                             //dodawanie nowego elementu na koniec vektora
    }

    const Pytanie &getPytanie() const
    {
        return pytanie;
    }
};

class Drukarz
{
public:
    virtual void Drukuj(const Test &test) const = 0;
    virtual ~Drukarz() {}
};

class DrukarzCSV : public Drukarz
{
public:
    void Drukuj(const Test &test) const
    {
        ofstream file("test.csv");
        if (file.is_open())
        {
            file << "Imie, nazwisko, liczba Pytan\n";
            file << test.getStudent().getImie() << ", " << test.getStudent().getNazwisko() << ", " << test.getLiczbaPytan() << "\n";
            file.close();
            cout << "Test zapisany do pliku test.csv w formacie CSV\n";
        }
        else
        {
            cout << "Nie mozna otworzyc pliku test.csv do zapisu\n";
        }
    }
};

class DrukarzXML : public Drukarz
{
public:
    void Drukuj(const Test &test) const
    {
        ofstream file("test.xml");
        if (file.is_open())
        {
            file << "<Test>\n";
            file << "\t<Imie> " << test.getStudent().getImie() << " </Imie>\n";
            file << "\t<Nazwisko> " << test.getStudent().getNazwisko() << " </nazwisko>\n";
            file << "\t<LiczbaPytan> " << test.getLiczbaPytan() << " </liczbaPytan>\n";
            file << "</Test>\n";
            file.close();
            cout << "Test zapisany do pliku test.xml w formacie XML\n";
        }
        else
        {
            cout << "Nie mozna otworzyc pliku test.xml do zapisu\n";
        }
    }
};

class DrukarzEkran : public Drukarz
{
public:
    void Drukuj(const Test &test) const
    {
        cout << "Imie: " << test.getStudent().getImie() << "\n";
        cout << "Nazwisko: " << test.getStudent().getNazwisko() << "\n";
        cout << "Liczba pytan: " << test.getLiczbaPytan() << "\n";
    }
};

class Egzaminator
{
public:
    vector<Test> testy;
    const Drukarz &drukarz;
    const Oceniacz &oceniacz;
    const Drukarz* drukarz_;
    const Oceniacz* oceniacz_;

    Egzaminator(const Drukarz &d, const Oceniacz &o) : drukarz(d), oceniacz(o) {}

    void DodajTest(const Test &test)
    {
        testy.push_back(test);
    }

    void OcenWszystko() const
    {
        for (int i = 0; i < testy.size(); i++)
        {
            const Test &test = testy[i];
            float wynik = oceniacz.Ocen(test.getPytanie());
            cout << "Wynik oceny dla studenta " << test.getStudent().getImie() << " " << test.getStudent().getNazwisko() << ": " << wynik << "\n";
        }
    }

    void DrukujWszystko() const
    {
        for (int i = 0; i < testy.size(); i++)
        {
            const Test &test = testy[i];
            drukarz_->Drukuj(test);                                             //polimorfizm
        }
    }
    void setDrukarz(const Drukarz& drukarz) {
        drukarz_ = &drukarz;
    }

    void setOceniacz(const Oceniacz& oceniacz) {
        oceniacz_ = &oceniacz;
    }
};

int main()
{
    DrukarzCSV drukarzCSV;
    DrukarzXML drukarzXML;
    DrukarzEkran drukarzEkran;

    Oceniacz1 oceniacz1;
    Oceniacz2 oceniacz2;
    Oceniacz3 oceniacz3;

    Egzaminator egzaminator(drukarzCSV, oceniacz1);

    Pytanie pytanie;
    pytanie.UstawOdpowiedzi({Odpowiedz::TRUE_POSITIVE, Odpowiedz::TRUE_NEGATIVE, Odpowiedz::FALSE_NEGATIVE});

    Student student1("Jan", "Kowalski");
    Test test1(3, student1);
    test1.dodajPytanie(pytanie);

    egzaminator.DodajTest(test1);
    egzaminator.setDrukarz(drukarzXML);
    egzaminator.setOceniacz(oceniacz2);

    egzaminator.OcenWszystko();
    egzaminator.DrukujWszystko();

    egzaminator.setDrukarz(drukarzEkran);

    egzaminator.OcenWszystko();
    egzaminator.DrukujWszystko();

    return 0;
}







