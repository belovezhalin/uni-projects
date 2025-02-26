//Anhelina Belavezha
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout.precision(10);
    cout<<scientific;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        float P, S;
        cin >> P >> S;
        //q = x2/x1 = x3/x2
        //x1 = x2/q
        //x3 = qx2
        //P = x1x2x3 = (x2/q)x2(qx2)
        //P = (x2)^3
        //x2 = potrojny pierwiastek(P)
        float triple_root = cbrt(P);
        //x1 + x2 + x3 = S
        //x1 + qx1 + qqx1 = S
        //x1(1 + q + q^2) = S
        //P = (x2)^3 = (qx1)^3
        //q = (P)^(1/3) / x1
        //x1(1 + (P)^(1/3) / x1 + ((P)^(1/3) / x1)^2) = S
        //x1 + (P)^(1/3) + (P)^(2/3) / x1 = S
        //x1^2 + x1(P)^(1/3) + (P)^(2/3) = x1S
        //x1^2 + x1(P)^(1/3) - x1S + (P)^(2/3) = 0
        //x1^2 + x1((P)^(1/3) - S) + (P)^(2/3) = 0
        //x1^2 + x1((P)^(1/3) - S) + (P)^(2/3) = 0
        //x1^2 - 2x1(-(P)^(1/3) + S) / 2 + (P)^(2/3) = 0  - rownanie kwadratowe ax^2 + bx + c = 0 (a = 1)
        float b = (-triple_root + S) / 2.0;
        float y1, y2, delta;
        //x1^2 - 2x1b + (P)^(2/3) = 0
        //(delta)^(1/2) = (4b^2 - 4(P)^(2/3))^(1/2) = 2(b^2 - (P)^(2/3))^(1/2) = 2(b - triple_root)^(1/2)*(b + triple_root)^(1/2) - algorytm (a - b)(a + b) jest tu szybszy od (a - b)^2

        //algorytm z 3 wykladu, wyznaczenie pierwiastkow kwadratowych

        //obliczanie delty
        float term1, term2;
        if(b - triple_root >= 0 && b + triple_root >= 0) {
            term1 = sqrt(b - triple_root);
            term2 = sqrt(b + triple_root);
            delta = term1 * term2;
        }
        else if(b - triple_root <= 0 && b + triple_root <= 0) {
            term1 = sqrt(-b + triple_root);
            term2 = sqrt(-b - triple_root);
            delta = term1 * term2;
        }
        else {
            cout << 0.0 << " " << 0.0 << " " << 0.0 << endl;
            continue;
        }

        if(b >= 0) {
            y1 = b + delta;
            y2 = pow(triple_root, 2.0) / y1;  
        }
        else {
            y2 = b - delta;
            y1 = pow(triple_root, 2.0) / y2;
        }

        //w zaleznosci od tego, jakie jest q, ciag moze byc malejacy/rosnacy, ukladamy zgodnie z x1>=x3
        float q;
        if(triple_root != 0) {
            if(y1 != 0) {
                q = triple_root / y1;
                if(q >= 1 && P > 0) {
                    cout << y1 * q * q << " " << y1 * q << " " << y1 << endl;
                } 
                else {
                    cout << y1 << " " << y1 * q << " " << y1 * q * q << endl;
                }
            }
            else if(y2 != 0) {
                q = triple_root / y2;
                if(q >= 1 && P > 0) {
                    cout << y2 * q * q << " " << y2 * q << " " << y2 << endl;
                } 
                else {
                    cout << y2 << " " << y2 * q << " " << y2 * q * q << endl;
                }
            } 
            else {
                cout << 0.0 << " " << 0.0 << " " << 0.0 << endl;
            }
        }
        else {
            cout << 0.0 << " " << 0.0 << " " << 0.0 << endl;
        }
    }
    return 0;
}