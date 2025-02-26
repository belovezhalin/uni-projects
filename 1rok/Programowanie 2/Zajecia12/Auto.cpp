#include <iostream>
using namespace std;

void UseAuto() {
    int x;
    double y;

    cout << "Wprowadz wartosc x: ";
    cin >> x;

    cout << "Wprowadz wartosc y: ";
    cin >> y;

    auto sum = x + y;                                        //program samodzielnie zrozumie typ zmiennej sum

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "sum: " << sum << endl;
}
