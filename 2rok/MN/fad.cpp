//Anhelina Belavezha
#include <iostream>
#include <iomanip>
#include <cmath>
#include "funkcja.h"
using namespace std;

class FAD {
    public: 
    
    class Operations {
        public:
        double f, fx, fy, fxy, fxx, fyy;

        void setf(double a) {
            this->f = a;
        }

        void setfx(double a) {
            this->fx = a;
        }

        void setfy(double a) {
            this->fy = a;
        }

        void setfxy(double a) {
            this->fxy = a;
        }

        void setfxx(double a) {
            this->fxx = a;
        }

        void setfyy(double a) {
            this->fyy = a;
        }

        Operations(double f, double fx, double fy, double fxy, double fxx, double fyy) {
            this->f = f;
            this->fx = fx;
            this->fy = fy;
            this->fxy = fxy;
            this->fxx = fxx;
            this->fyy = fyy;
        }

        Operations() {
            this->f = 0;
            this->fx = 0;
            this->fy = 0;
            this->fxy = 0;
            this->fxx = 0;
            this->fyy = 0;
        }

        Operations (const Operations &operation) {
            this->f = operation.f;
            this->fx = operation.fx;
            this->fy = operation.fy;
            this->fxy = operation.fxy;
            this->fxx = operation.fxx;
            this->fyy = operation.fyy;
        }

        Operations operator+(const Operations &a) const  {
            const Operations* operation = new const Operations(f + a.f, fx + a.fx, fy + a.fy, fxy + a.fxy, fxx + a.fxx, fyy + a.fyy);
            return *operation;
        }

        Operations operator+(const double a) const {
            const Operations* operation = new const Operations(f + a, fx, fy, fxy, fxx, fyy);
            return *operation;
        }

        Operations operator-(const Operations &a) const {
            const Operations* operation = new const Operations(f - a.f, fx - a.fx, fy - a.fy, fxy - a.fxy, fxx - a.fxx, fyy - a.fyy);
            return *operation;
        }

        Operations operator-(const double a) const {
            const Operations* operation = new const Operations(f - a, fx, fy, fxy, fxx, fyy);
            return *operation;
        }

        Operations operator*(const Operations &a) const {
            const Operations* operation = new const Operations(f * a.f, fx * a.f + f * a.fx, fy * a.f + f * a.fy, fx * a.fy + fy * a.fx + fxy * a.f + f * a.fxy, fxx * a.f + 2 * fx * a.fx + f * a.fxx, fyy * a.f + 2 * fy * a.fy + f * a.fyy);
            return *operation;
        }

        Operations operator/(const Operations &a) const {
            const Operations* operation = new const Operations(f / a.f, (fx - (f / a.f * a.fx)) / a.f, (fy - (f / a.f * a.fy)) / a.f, (2 * f * a.fy * a.fx + a.f * a.f * fxy) / (a.f * a.f * a.f) - (a.fy * fx + fy * a.fx + f * a.fxy) / (a.f * a.f), (2*f * a.fx * a.fx + a.f * a.f * fxx ) / (a.f * a.f * a.f) - (2 * fx * a.fx + f * a.fxx) / (a.f * a.f), (2*f * a.fy * a.fy + a.f * a.f * fyy) / (a.f * a.f * a.f) - (2 * fy * a.fy + f * a.fyy) / (a.f * a.f));
            return *operation;
        }

        Operations operator/(const double a) const {
            const Operations* operation = new const Operations(f / a, fx / a, fy / a, fxy / a, fxx / a, fyy / a );
            return *operation;
        }

        Operations operator-() const {
            const Operations* operation = new const Operations(-f, -1 * fx, -1 * fy, -1 * fxy, -1 * fxx, -1 * fyy);
            return *operation;
        }

        Operations operator=(Operations &a)  {
            const Operations* operation = new const Operations(a.f, a.fx, a.fy, a.fxy, a.fxx, a.fyy);
            return *operation;
        }
    };

    void printFAD(double x1, double y1) {
        const Operations* x = new const Operations(x1, 1, 0, 0, 0, 0);
        const Operations* y = new const Operations(y1, 0, 1, 0, 0, 0);

        FAD::Operations results = funkcja(*x, *y);

        cout.precision(15);
        cout << results.f << " ";
        cout << results.fx << " ";
        cout << results.fy << " ";
        cout << results.fxx << " ";
        cout << results.fxy << " ";
        cout << results.fyy << endl;
    }
};

FAD::Operations operator*(const double a, const FAD::Operations &b) {
    const FAD::Operations* operation = new const FAD::Operations(b.f * a, b.fx * a, b.fy * a, b.fxy * a , a * b.fxx, a * b.fyy);
    return *operation;
}

FAD::Operations operator-(const double a, const FAD::Operations &b) {
    const FAD::Operations* operation = new const FAD::Operations(a - b.f, -b.fx, -b.fy, -b.fxy, -b.fxx, -b.fyy);
    return *operation;
}

FAD::Operations sin(const FAD::Operations &a) {
    const FAD::Operations* operation = new const FAD::Operations(sin(a.f), a.fx * cos(a.f), a.fy * cos(a.f), a.fxy * cos(a.f) - a.fy * a.fx * sin(a.f), a.fxx * cos(a.f) - a.fx * a.fx * sin(a.f), a.fyy * cos(a.f) - a.fy * a.fy * sin(a.f));
    return *operation;
}

FAD::Operations cos(const FAD::Operations &a) {
    const FAD::Operations* operation = new const FAD::Operations(cos(a.f), -1 * a.fx * sin(a.f), -1 * a.fy * sin(a.f), a.fy * a.fx * (-cos(a.f)) - a.fxy * sin(a.f), a.fx * a.fx * (-cos(a.f)) - (a.fxx * sin(a.f)), a.fy * a.fy * (-cos(a.f)) - (a.fyy * sin(a.f)));
    return *operation;
}

FAD::Operations exp(const FAD::Operations &a) {
    const FAD::Operations* operation = new const FAD::Operations(exp(a.f), a.fx * exp(a.f), a.fy * exp(a.f), exp(a.f) * (a.fy * a.fx + a.fxy), exp(a.f) * (a.fxx + a.fx * a.fx), exp(a.f) * (a.fyy + a.fy * a.fy));
    return *operation;
}

int main() {
    int n;
    cin >> n;

    FAD* fad = new FAD();

    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        fad->printFAD(x, y);
    }

    delete fad;
    return 0;
}