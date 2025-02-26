#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    double real; //czesc rzeczywista
    double imag; //czesc urojona

public:
    Complex(double realHere = 0.0, double imagHere = 0.0) : real(realHere), imag(imagHere) {} // konstruktory
    Complex() : real(0), imag(0) {}

    double GetReal() const
    { // gettery i settery
        return real;
    }

    double GetImag() const
    {
        return imag;
    }

    void SetReal(double realHere)
    {
        real = realHere;
    }

    void SetImag(double imagHere)
    {
        imag = imagHere;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////operatory dodawania

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex &operator+=(const Complex &other)
    {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////operatory odejmowania

    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex &operator-=(const Complex &other)
    {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////operatory mnożenia

    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }
    Complex &operator*=(const Complex &other)
    {
        double realHere = real * other.real - imag * other.imag;
        double imagHere = real * other.imag + imag * other.real;
        real = realHere;
        imag = imagHere;
        return *this;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////operatory dzielenia

    Complex operator/(const Complex &other) const
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0)
        {
            throw invalid_argument("Dzielimy przez zero");
        }
        double realHere = (real * other.real + imag * other.imag) / denominator;
        double imagHere = (imag * other.real - real * other.imag) / denominator;
        return Complex(realHere, imagHere);
    }

    Complex &operator/=(const Complex &other)
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0)
        {
            throw invalid_argument("Dzielimy przez zero");
        }
        double realHere = (real * other.real + imag * other.imag) / denominator;
        double imagHere = (imag * other.real - real * other.imag) / denominator;
        real = realHere;
        imag = imagHere;
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////operator wyjscia do strumienia

    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////operatory preinkrementacji i postinkrementacji

    Complex &operator++()
    {
        ++real;
        ++imag;
        return *this;
    }

    Complex operator++(int)
    {
        Complex tempo(*this);
        ++(*this);
        return tempo;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////operatory porownania

    bool operator==(const Complex &c) const
    {
        return (real == c.real && imag == c.imag);
    }

    bool operator!=(const Complex &c) const
    {
        return !(*this == c);
    }

    bool operator<(const Complex &c) const
    {
        return (real < c.real || (real == c.real && imag < c.imag));
    }

    bool operator>(const Complex &c) const
    {
        return !(*this < c || *this == c);
    }

    bool operator<=(const Complex &c) const
    {
        return (*this < c || *this == c);
    }

    bool operator>=(const Complex &c) const
    {
        return !(*this < c);
    }

    //////////////////////////////////////////////////////////////////////////////////////////////operatory nawiasow kwadratowych

    double &operator[](int index)
    {
        if (index == 0)
        {
            return real;
        }
        else if (index == 1)
        {
            return imag;
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }

    const double &operator[](int index) const
    {
        if (index == 0)
        {
            return real;
        }
        else if (index == 1)
        {
            return imag;
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////operator rzutowania na int

    operator int() const
    {
        if (imag != 0)
        {
            throw invalid_argument("Nie mozna skonwertowac czesc urojona na int");
        }
        return real;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////operator modulo

    Complex operator%(const Complex &other) const
    {
        double real_mod = fmod(real, other.real); // fmod zwaraca reszte z dzielenia
        double imag_mod = fmod(imag, other.imag);
        return Complex(real_mod, imag_mod);
    }
};

int main()
{
    Complex z1(2.0, 3.0);
    Complex z2(4.0, -1.0);
    Complex z3(0.0, 1.0);

    Complex z5 = z1 + z2;
    cout << "z5 = z1 + z2 = " << z5 << endl;

    Complex z6 = z1 - z2;
    cout << "z6 = z1 - z2 = " << z6 << endl;

    Complex z9 = ++z1;
    cout << "z9 = ++z1 = " << z9 << endl;

    z1[0] = 5.0;
    z1[1] = -2.0;
    cout << "z1 = " << z1 << endl;
}
