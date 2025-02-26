//Anhelina Belavezha
class POLYNOMIAL {
public:
    static int overloaded;
    int degree;
    int *pol;

    POLYNOMIAL();
    ~POLYNOMIAL();
    POLYNOMIAL(const POLYNOMIAL&);
    POLYNOMIAL(int, ...);

    POLYNOMIAL operator=(const POLYNOMIAL&);
    POLYNOMIAL operator+(const POLYNOMIAL&) const;
    POLYNOMIAL operator-(const POLYNOMIAL&) const;
    POLYNOMIAL operator-() const;
    POLYNOMIAL operator*(const POLYNOMIAL&) const;
    POLYNOMIAL operator/(const POLYNOMIAL&);
    POLYNOMIAL operator%(const POLYNOMIAL&);

    POLYNOMIAL operator+=(const POLYNOMIAL&);
    POLYNOMIAL operator-=(const POLYNOMIAL&);
    POLYNOMIAL operator*=(const POLYNOMIAL&);
    POLYNOMIAL operator/=(const POLYNOMIAL&);
    POLYNOMIAL operator%=(const POLYNOMIAL&);

    POLYNOMIAL operator++();
    POLYNOMIAL operator++(int);
    POLYNOMIAL operator--();
    POLYNOMIAL operator--(int);

    POLYNOMIAL operator<<(int);
    POLYNOMIAL operator<<=(int);
    POLYNOMIAL operator>>(int);
    POLYNOMIAL operator>>=(int);

    void GCD() const;
    void Normalize();

    void *operator new(size_t a);
    void operator delete(void *pointer);

    friend bool operator<(const POLYNOMIAL&, const POLYNOMIAL&);
    friend bool operator<=(const POLYNOMIAL&, const POLYNOMIAL&);
    friend bool operator==(const POLYNOMIAL&, const POLYNOMIAL&);
    friend bool operator>=(const POLYNOMIAL&, const POLYNOMIAL&);
    friend bool operator>(const POLYNOMIAL&, const POLYNOMIAL&);
    friend bool operator!=(const POLYNOMIAL&, const POLYNOMIAL&);

    friend ostream &operator<<(ostream&, const POLYNOMIAL&);
    friend istream &operator>>(istream&, POLYNOMIAL&);
};
////////////////////////////////////////////////////////////////////////podprogramy wspomagajace
int GreatestCommonDivisor(int a, int b) {
    if(a == 0)
        return b;
    return GreatestCommonDivisor(b % a, a);
}

void POLYNOMIAL::GCD() const {
    int a = this->pol[0];
    for(int i = 1; i < this->degree + 1; i++) {
        a = GreatestCommonDivisor(this->pol[i], a);
    }
    if(a == 1) 
       return;
    if(a < 0) 
       a = -a;
    for(int i = 0; i < this->degree + 1; i++)
        this->pol[i] /= a;
}

void POLYNOMIAL::Normalize() {                                     //funkcja przesuwa wielomian poprzez usuniecie zerowych wspolczynnikow na koncu tablicy
    int i = this->degree;                                          //i aktualizacje stopnia wielomianu oraz tablicy wspolczynnikow do nowych wartosci
    while(this->pol[i] == 0) {
        i--;
        if(i < 0) {
            delete[] this->pol;
            this->degree = 0;
            this->pol = new int[this->degree + 1];
            this->pol[0] = 0;
            return;
        }
    }
    int *newpol = new int[i + 1];
    for(int j = 0; j < i + 1; j++) {
        newpol[j] = this->pol[j];
    }
    delete[] this->pol;
    this->degree = i;
    this->pol = newpol;
}
////////////////////////////////////////////////////////////////////////operatory pamieci
void *POLYNOMIAL::operator new(size_t a) {
    overloaded++;
    return ::operator new(a);
}

void POLYNOMIAL::operator delete(void *pointer) {
    overloaded--;
    ::operator delete(pointer);
}
///////////////////////////////////////////////////////////////////////operatory wejscia/wyjscia strumieniowego
ostream &operator<<(ostream &stream, const POLYNOMIAL &polynomial) {
    stream << "( ";
    for(int i = 0; i < polynomial.degree; i++)
        stream << polynomial.pol[i] << ", ";
    stream << polynomial.pol[polynomial.degree] << " )";
    return stream;
}

istream &operator>>(istream &stream, POLYNOMIAL &polynomial) {
    delete[] polynomial.pol;
    stream >> polynomial.degree;
    if(polynomial.degree < 0) {
        polynomial.degree = 0;
        polynomial.pol = new int[polynomial.degree + 1];
        *(polynomial.pol) = 0;
        return stream;
    }
    if(polynomial.degree == 0) {
        polynomial.pol = new int[polynomial.degree + 1];
        stream >> *(polynomial.pol);
        if(*(polynomial.pol) == 0) return stream;
    } 
    else {
        polynomial.pol = new int[polynomial.degree + 1];
        for(int i = 0; i < polynomial.degree + 1; i++)
            stream >> polynomial.pol[i];
    }
    polynomial.GCD();
    return stream;
}
//////////////////////////////////////////////////////////////////////przeladowania globalne
bool operator==(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    if(a.degree == b.degree) {
        for(int i = 0; i < a.degree + 1; i++) {
            if (a.pol[i] != b.pol[i]) return false;
        }
        return true;
    }
    return false;
}

bool operator!=(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    return !(a == b);
}

bool operator<(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    if(a.degree < b.degree) return true;
    if(a.degree > b.degree) return false;
    for(int i = a.degree; i >= 0; i--) {
        if(a.pol[i] < b.pol[i]) return true;
        if(a.pol[i] > b.pol[i]) return false;
    }
    return false;
}

bool operator<=(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    return a == b || a < b;
}

bool operator>(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    if(a.degree > b.degree) return true;
    if(a.degree < b.degree) return false;
    for(int i = a.degree; i >= 0; i--) {
        if(a.pol[i] > b.pol[i]) return true;
        if(a.pol[i] < b.pol[i]) return false;
    }
    return false;
}

bool operator>=(const POLYNOMIAL &a, const POLYNOMIAL &b) {
    return a == b || a > b;
}
/////////////////////////////////////////////////////////////////////konstruktory i destruktor
POLYNOMIAL::POLYNOMIAL() {
    this->degree = 0;
    this->pol = new int[1];
    this->pol[0] = 0;
}

POLYNOMIAL::~POLYNOMIAL() {
    delete[] this->pol;
}

POLYNOMIAL::POLYNOMIAL(const POLYNOMIAL &a) {
    this->degree = a.degree;
    this->pol = new int[this->degree + 1];
    for(int i = 0; i < this->degree + 1; i++) {
        this->pol[i] = a.pol[i];
    }
}

POLYNOMIAL::POLYNOMIAL(int degree, ...) {
    if(degree < 0) {
        this->degree = 0;
        this->pol = new int[this->degree + 1];
        return;
    }

    this->degree = degree;
    this->pol = new int[this->degree + 1];

    va_list args;
    va_start(args, degree);
    for(int i = 0; i < this->degree + 1; i++) {
        this->pol[i] = va_arg(args, int);
    }
    va_end (args);

    if(this->degree == 0 && this->pol[0] == 0) return;
    this->GCD();
}
////////////////////////////////////////////////////////////////////przeladowane operatory
POLYNOMIAL POLYNOMIAL::operator=(const POLYNOMIAL &a) {
    delete[] this->pol;
    this->degree = a.degree;
    this->pol = new int[this->degree + 1];
    for  (int i = 0; i < this->degree + 1; i++) {
        this->pol[i] = a.pol[i];
    }
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator+(const POLYNOMIAL &a) const {
    if(this->degree >= a.degree) {
        POLYNOMIAL b(this->degree);
        for(int i = 0; i < this->degree + 1; i++) {
            b.pol[i] = this->pol[i];
            if(i < a.degree + 1)
                b.pol[i] += a.pol[i];
        }
        b.Normalize();
        if(b.degree == 0 && b.pol[0] == 0) return b;
        b.GCD();
        return b;
    } 
    else {
        POLYNOMIAL b(a.degree);
        for(int i = 0; i < a.degree + 1; i++) {
            if(i < this->degree + 1)
                b.pol[i] = this->pol[i];
            else
                b.pol[i] = 0;
            b.pol[i] += a.pol[i];
        }
        b.Normalize();
        if(b.degree == 0 && b.pol[0] == 0) return b;
        b.GCD();
        return b;
    }
}

POLYNOMIAL POLYNOMIAL::operator-(const POLYNOMIAL &a) const {
    if(this->degree >= a.degree) {
        POLYNOMIAL b(this->degree);
        for(int i = 0; i < this->degree + 1; i++) {
            b.pol[i] = this->pol[i];
            if(i < a.degree + 1)
                b.pol[i] -= a.pol[i];
        }
        b.Normalize();
        if(b.degree == 0 && b.pol[0] == 0) return b;
        b.GCD();
        return b;
    } 
    else {
        POLYNOMIAL b(a.degree);
        for(int i = 0; i < a.degree + 1; i++) {
            if(i < this->degree + 1)
                b.pol[i] = this->pol[i];
            else
                b.pol[i] = 0;
            b.pol[i] -= a.pol[i];
        }
        b.Normalize();
        if (b.degree == 0 && b.pol[0] == 0) return b;
        b.GCD();
        return b;
    }
}

POLYNOMIAL POLYNOMIAL::operator-() const {
    POLYNOMIAL a(this->degree);
    delete[] a.pol;
    a.pol = new int[this->degree + 1];
    for(int i = 0; i < this->degree + 1; i++) {
        a.pol[i] = -this->pol[i];
    }
    return a;
}

POLYNOMIAL POLYNOMIAL::operator*(const POLYNOMIAL &a) const {
    if((this->degree == 0 && this->pol[0] == 0) || (a.degree == 0 && a.pol[0] == 0)) {
        POLYNOMIAL b;
        return b;
    }
    POLYNOMIAL b(this->degree + a.degree);
    delete[] b.pol;
    b.pol = new int[b.degree + 1];
    for(int i = 0; i < b.degree + 1; i++)
        b.pol[i] = 0;
    for(int i = 0; i < this->degree + 1; i++) {
        for(int j = 0; j < a.degree + 1; j++)
            b.pol[i + j] += this->pol[i] * a.pol[j];
    }
    b.Normalize();
    if(b.degree == 0 && b.pol[0] == 0) return b;
    b.GCD();
    return b;
}

POLYNOMIAL POLYNOMIAL::operator/(const POLYNOMIAL &a) {
    if((a.degree == 0 && a.pol[0] == 0) || (this->degree < a.degree)) return POLYNOMIAL();
    if(*this == a) return POLYNOMIAL(0, 1);
    if(a.degree == 0 && a.pol[0] == -1) return *this * a;
    if(a.degree == 0 && a.pol[0] == -1) return *this;

    class DIVISION {
    public:
        int numerator;
        int denominator;

        void Negative() {
            if(numerator < 0 && denominator < 0) {
                numerator *= -1;
                denominator *= -1;
                return;
            }
            if(numerator >= 0 && denominator < 0) {
                numerator *= -1;
                denominator *= -1;
                return;
            }
        }
    };

    int dividentsize = this->degree + 1;                                  //divident/divisor = quotient
    int divisorsize = a.degree + 1;
    int quotientsize = this->degree - a.degree + 1;

    DIVISION *divident = new DIVISION[dividentsize];
    DIVISION *divisor = new DIVISION[divisorsize];
    DIVISION *quotient = new DIVISION[quotientsize];

    for(int i = 0; i < this->degree + 1; i++) {
        divident[i].numerator = this->pol[this->degree - i];
        divident[i].denominator = 1;
    }

    for(int i = 0; i < a.degree + 1; i++) {
        divisor[i].numerator = a.pol[a.degree - i];
        divisor[i].denominator = 1;
    }

    int q = 0;
    while(q != quotientsize) {
        quotient[q].numerator = divident[q].numerator * divisor[0].denominator;
        quotient[q].denominator = divident[q].denominator * divisor[0].numerator;
        quotient[q].Negative();

        DIVISION *currentdivisor = new DIVISION[divisorsize];

        for(int i = 0; i < divisorsize; i++) {
            currentdivisor[i].numerator = divisor[i].numerator * quotient[q].numerator;
            currentdivisor[i].denominator = divisor[i].denominator * quotient[q].denominator;
            currentdivisor[i].Negative();
        }

        for(int i = 0; i < dividentsize; i++) {
            divident[i].numerator *= quotient[0].denominator;
            divident[i].denominator *= quotient[0].denominator;
        }

        for(int i = 0; i < divisorsize; i++) {
            divident[q + i].numerator -= currentdivisor[i].numerator;
        }

        delete[] currentdivisor;
        q++;
    }

    int tempo = divisor[0].numerator;
    int tempo2 = divisor[0].numerator;
    if(tempo2 < 0) tempo2 *= -1;
    if(tempo < 0) tempo *= -1;

    for(int i = quotientsize - 2; i >= 0; i--) {
        quotient[i].numerator *= tempo;
        quotient[i].denominator *= tempo;
        tempo *= tempo2;
    }

    POLYNOMIAL b(this->degree - a.degree);
    for(int i = 0; i < this->degree - a.degree + 1; i++) {
        b.pol[i] = quotient[this->degree - a.degree - i].numerator;
    }

    delete[] divident;
    delete[] divisor;
    delete[] quotient;

    b.Normalize();
    if(b.degree == 0 && b.pol[0] == 0) return b;
    b.GCD();
    return b;
}

POLYNOMIAL POLYNOMIAL::operator%(const POLYNOMIAL &a) {
    if((a.degree == 0 && a.pol[0] == 0) || (this->degree < a.degree)) return POLYNOMIAL(*this);
    if((*this == a) || (a.degree == 0 && a.pol[0] == 0) || (this->degree < a.degree)) return POLYNOMIAL();
    if(*this == a) return POLYNOMIAL(0, 1);

    class DIVISION {
    public:
        int numerator;
        int denominator;

        void Negative() {
            if(numerator < 0 && denominator < 0) {
                numerator *= -1;
                denominator *= -1;
                return;
            }
            if(numerator >= 0 && denominator < 0) {
                numerator *= -1;
                denominator *= -1;
                return;
            }
        }
    };

    int dividentsize = this->degree + 1;
    int divisorsize = a.degree + 1;
    int quotientsize = this->degree - a.degree + 1;

    DIVISION *divident = new DIVISION[dividentsize];
    DIVISION *divisor = new DIVISION[divisorsize];
    DIVISION *quotient = new DIVISION[quotientsize];

    for(int i = 0; i < this->degree + 1; i++) {
        divident[i].numerator = this->pol[this->degree - i];
        divident[i].denominator = 1;
    }

    for(int i = 0; i < a.degree + 1; i++) {
        divisor[i].numerator = a.pol[a.degree - i];
        divisor[i].denominator = 1;
    }

    int q = 0;
    while(q != quotientsize) {
        quotient[q].numerator = divident[q].numerator * divisor[0].denominator;
        quotient[q].denominator = divident[q].denominator * divisor[0].numerator;
        quotient[q].Negative();

        DIVISION *currentdivisor = new DIVISION[divisorsize];
        for(int i = 0; i < divisorsize; i++) {
            currentdivisor[i].numerator = divisor[i].numerator * quotient[q].numerator;
            currentdivisor[i].denominator = divisor[i].denominator * quotient[q].denominator;
            currentdivisor[i].Negative();
        }

        for(int i = 0; i < dividentsize; i++) {
            divident[i].numerator *= quotient[0].denominator;
            divident[i].denominator *= quotient[0].denominator;
        }

        for(int i = 0; i < divisorsize; i++) {
            divident[q + i].numerator -= currentdivisor[i].numerator;
        }

        delete[] currentdivisor;
        q++;
    }

    POLYNOMIAL b(a.degree - 1);

    int i = 0;
    while(b.degree + 1 != i) {
        b.pol[i] = divident[dividentsize - 1 - i].numerator;
        i++;
    }

    delete[] divident;
    delete[] divisor;
    delete[] quotient;

    b.Normalize();
    if(b.degree == 0 && b.pol[0] == 0) return b;
    b.GCD();
    return b;
}
///////////////////////////////////////////////////////////////////wersja kompozycyjna przeladowania operatorow
POLYNOMIAL POLYNOMIAL::operator+=(const POLYNOMIAL &a) {
    *this = *this + a;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator-=(const POLYNOMIAL &a) {
    *this = *this - a;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator*=(const POLYNOMIAL &a) {
    *this = *this * a;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator/=(const POLYNOMIAL &a) {
    *this = *this / a;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator%=(const POLYNOMIAL &a) {
    *this = *this % a;
    return *this;
}
///////////////////////////////////////////////////////////////////inkrementacja i dekrementacja(prefiksowa, postfiksowa)
POLYNOMIAL POLYNOMIAL::operator++() { 
    for(int i = 0; i < this->degree + 1; i++) {
        ++this->pol[i];
    }

    this->Normalize();
    if(this->degree == 0 && this->pol[0] == 0) return *this;
    this->GCD();
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator++(int) { 
    POLYNOMIAL tempo(*this);
    operator++();
    return tempo;
}

POLYNOMIAL POLYNOMIAL::operator--() { 
    for(int i = 0; i < this->degree + 1; i++) {
        --this->pol[i];
    }

    this->Normalize();
    if(this->degree == 0 && this->pol[0] == 0) return *this;
    this->GCD();
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator--(int) { 
    POLYNOMIAL tempo(*this);
    operator--();
    return tempo;
}
//////////////////////////////////////////////////////////////////operatory bitowe
POLYNOMIAL POLYNOMIAL::operator<<(int q) {
    POLYNOMIAL a(*this);

    if(q < 0 || a.degree - q < 0) {
        a.degree = 0;
        delete[] a.pol;
        a.pol = new int[a.degree + 1];
        a.pol[0] = 0;
        return a;
    }

    if(q == 0) {
        return a;
    }

    int *newpol = new int[a.degree - q + 1];
    for(int i = q; i < a.degree + 1; i++) {
        newpol[i - q] = a.pol[i];
    }

    delete[] a.pol;
    a.degree = a.degree - q;
    a.pol = newpol;

    a.Normalize();
    if(a.degree == 0 && a.pol[0] == 0) return *this;
    a.GCD();
    return a;
}

POLYNOMIAL POLYNOMIAL::operator>>(int q) {
    POLYNOMIAL a(*this);

    if (q < 0) {
        a.degree = 0;
        delete[] a.pol;
        a.pol = new int[a.degree + 1];
        a.pol[0] = 0;
        return a;
    }
    if (q == 0) {
        return a;
    }

    int *newpol = new int[a.degree + q + 1];
    int i = 0;
    while (i < q) {
        newpol[i] = 0;
        i++;
    }
    while (i < a.degree + q + 1) {
        newpol[i] = a.pol[i - q];
        i++;
    }
    delete[] a.pol;
    a.degree = a.degree + q;
    a.pol = newpol;

    a.Normalize();
    if (a.degree == 0 && a.pol[0] == 0) return *this;
    a.GCD();
    return a;
}

POLYNOMIAL POLYNOMIAL::operator<<=(int value) {
    *this = *this << value;
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator>>=(int value) {
    *this = *this >> value;
    return *this;
}












