#include <iostream>
using namespace std;

class Kvector
{
    int *m;
    int len;

public:
    Kvector(int sz = 0, int value = 0); // constructor
    Kvector(Kvector &v);                // copy constructor
    ~Kvector()
    {
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    void print() const
    {
        for (int i = 0; i < len; i++)
            cout << m[i] << " ";
        cout << endl;
    }
    void clear()
    {
        delete[] m;
        m = nullptr;
        len = 0;
    }
    int size() { return len; }
    Kvector &operator=(const Kvector &v);
    friend bool operator==(const Kvector &v, const Kvector &w);
    friend ostream &operator<<(ostream &os, const Kvector &v);
    int &operator[](int idx) { return m[idx]; }
};

Kvector::Kvector(int sz, int value) : len(sz)
{
    cout << this << " : Kvector(int, int)" << endl;
    m = new int[len + 1];
    for (int i = 0; i < len; i++)
    {
        m[i] = value;
    }
    m[len] = '\0';
}

Kvector::Kvector(Kvector &v)
{
    cout << this << " : Kvector(Kvector&)" << endl;
    len = v.len;
    m = new int[len + 1];
    for (int i = 0; i < len; i++)
    {
        m[i] = v.m[i];
    }
    m[len] = '\0';
}

Kvector &Kvector::operator=(const Kvector &v)
{
    len = v.len;
    m = new int[len + 1];
    for (int i = 0; i < len; i++)
    {
        m[i] = v.m[i];
    }
    m[len] = '\0';
    return *this;
}

bool operator==(const Kvector &v, const Kvector &w)
{
    if (v.len == w.len)
    {
        int i = 0, flag = 1;
        while (i == v.len)
        {
            if (v.m[i] != w.m[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}

bool operator!=(const Kvector &v, const Kvector &w)
{
    return !(v == w);
}

ostream &operator<<(ostream &os, const Kvector &v)
{
    for (int i = 0; i < v.len; i++)
    {
        os << v.m[i] << " ";
    }
    return os;
}
int main()
{
    Kvector v1(3);
    v1.print();
    Kvector v2(2, 9);
    v2.print();
    Kvector v3(v2);
    v3.print();

    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;

    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;

    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
}