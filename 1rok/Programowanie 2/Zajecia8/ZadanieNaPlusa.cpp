#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "To zwierze robi dzwiek!" << endl;
    }
    virtual ~Animal() {
        cout << "Zwierze poszlo odpoczywac..." << endl;
    }
};

class Mammal : virtual public Animal {
public:
    virtual void eat() {
        cout << "Ten ssak je!" << endl;
    }
    virtual ~Mammal() {
        cout << "Ssak poszedl odpoczywac..." << endl;
    }
};

class Bird : virtual public Animal {
public:
    virtual void fly() {
        cout << "Ten ptak lata!" << endl;
    }
    virtual ~Bird() {
        cout << "Ten ptak odpoczywa..." << endl;
    }
};

class Dog : public Mammal {
public:
    void makeSound() {
        cout << "HAU!" << endl;
    }
    void eat() {
        cout << "Ten pies je mieso" << endl;
    }
    ~Dog() {
        cout << "Ten pies odpoczywa..." << endl;
    }
};

class Cat : public Mammal {
public:
    void makeSound() {
        cout << "MIAU!" << endl;
    }
    void eat() {
        cout << "Ten kot je rybek!" << endl;
    }
    ~Cat() {
        cout << "Ten kot odpoczywa..." << endl;
    }
};

class Eagle : public Bird {
public:
    void makeSound() {
        cout << "AUAUA!" << endl;
    }
    void fly() {
        cout << "Ten orzel lata!" << endl;
    }
    ~Eagle() {
        cout << "Orzel odpoczywa..." << endl;
    }
};

class Parrot : public Bird {
public:
    void makeSound() {
        cout << "Ja papuga! Ja papuga!" << endl;
    }
    void fly() {
        cout << "Ta papuga lata w nocy i krzyczy! " << endl;
    }
    ~Parrot() {
        cout << "Papuga odpoczywa..." << endl;
    }
};

class Bat : public Mammal, public Bird {
public:
    void makeSound() {
        cout << "Chhhhh!" << endl;
    }
    void eat() {
        cout << "Ten nietopierz cos je!" << endl;
    }
    void fly() {
        cout << "Ten nietopierz lata w nocy!" << endl;
    }
    ~Bat() {
        cout << "Nietopierz odpoczywa..." << endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->makeSound();
    Mammal* mammal = new Cat();
    mammal->eat();
    Bird* bird = new Eagle();
    bird->fly();
    Parrot* parrot = new Parrot();
    parrot->makeSound();
    Bat* bat = new Bat();
    bat->fly();

    delete animal;
    delete mammal;
    delete bird;
    delete parrot;
    delete bat;

    return 0;
}
