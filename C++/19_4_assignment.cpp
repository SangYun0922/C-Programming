#include <iostream>
using namespace std;

class Complex
{
    double re, im;

public:
    Complex(double r = 0, double i = 0) : re(r), im(i)
    {
    }
    ~Complex() {}
    double real() { return re; }
    double imag() { return im; }
    Complex &operator=(const Complex &c);
    friend Complex operator+(const Complex &c, const Complex &d);
    friend bool operator==(const Complex &c, const Complex &d);
    friend ostream &operator<<(ostream &os, const Complex &c);
};

ostream &operator<<(ostream &os, const Complex &c)
{
    os << c.re << " + " << c.im << "i ";
    return os;
}

Complex &Complex::operator=(const Complex &c)
{
    re = c.re;
    im = c.im;
    return *this;
}

Complex operator+(const Complex &c, const Complex &d)
{
    Complex result(c.re + d.re, c.im + d.im);
    return result;
}

bool operator==(const Complex &c, const Complex &d)
{
    return ((c.re == d.re) && (c.im == d.im));
}

bool operator!=(const Complex &c, const Complex &d)
{
    return !(c == d);
}
int main()
{
    Complex x(2, 3);
    Complex y(-1, -3), z;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    z = x + y;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << (x != y) << endl;
    return 0;
}
