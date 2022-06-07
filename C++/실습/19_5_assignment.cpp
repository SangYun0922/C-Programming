#include <iostream>
using namespace std;

enum COMPLEX_PART
{
    RE,
    IM
};

class Complex
{
    double re, im;

public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    ~Complex() {}
    operator double() const { return re; }
    double real() { return re; }
    double imag() { return im; }
    Complex &operator=(const Complex &c);
    Complex &operator++()
    {
        this->re++;
        return *this;
    }
    Complex operator++(int)
    {
        Complex tmp(this->re, this->im);
        operator++();
        return tmp;
    }
    Complex &operator+=(const Complex &d);
    double &operator[](COMPLEX_PART idx);
    friend Complex operator+(Complex tmp, const Complex &d);
    friend bool operator==(const Complex &c, const Complex &d);
    friend ostream &operator<<(ostream &os, const Complex &c);
};

double &Complex::operator[](COMPLEX_PART idx)
{
    return (idx ? im : re);
}
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

Complex &Complex::operator+=(const Complex &d)
{
    re = re + d.re;
    im = im + d.im;
    return *this;
}
Complex operator+(Complex tmp, const Complex &d)
{
    tmp += d;
    return tmp;
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
    double d = 3.141594;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "d = " << d << endl;

    z = x++;
    cout << "x = " << x << endl;
    cout << "z = " << z << endl;
    z = ++x;
    cout << "x = " << x << endl;
    cout << "z = " << z << endl;

    z += x;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << (x != y) << endl;

    z[IM] = x[RE];
    cout << "z = " << z << endl;

    z = d;
    cout << "z = " << z << endl;

    d = y;
    cout << "d = " << d << endl;

    return 0;
}
