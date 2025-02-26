//Anhelina Belavezha
#ifndef SOURCE_H
#define SOURCE_H

class spline {
public:
    spline(int n);
    ~spline();
    void set_points(double* x, double* y);
    double operator()(double z) const;

private:
    int n;
    double* h;
    double* x;
    double* y;
    double* z;

    void calc();
    double getA(int i) const;
    double getB(int i) const;
    double getC(int i) const;
};

#endif 
