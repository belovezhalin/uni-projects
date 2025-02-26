#include <iostream>
using namespace std;

template <typename T>
T &maximum(T &x, T &y)
// const T &maximum(const T &x, const T &y)
{
    // cout << "Maksimum z " << x << " i " << y << endl;
    return (x > y) ? x : y;
}

class Person
{
    int age;

public:
    Person(int _age)
    {
        age = _age;
    }
    void print() const
    {
        cout << "Person " << age << endl;
    }

    bool operator>(const Person &other) const
    {
        return age > other.age;
    }
    // friend ostream &operator<<(ostream &os, const Person &person);
};

// ostream &operator<<(ostream &os, const Person &person)
// {
//     os << "Person " << person.age;
//     return os;
// }

int main()
{
    Person p1(10), p2(12);
    const Person &result = maximum(p1, p2);
    // Person &result = maximum(p1, p2);
    result.print();

    // int i = maximum(3, 7);
    // std::cout << i << '\n';

    // double d = maximum(6.34, 'a');
    // double d = maximum(6.34, ((double)'a'));
    // std::cout << d << '\n';

    // char ch = maximum('a', '6');
    // std::cout << ch << '\n';

    return 0;
}
