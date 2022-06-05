#include <iostream>
using namespace std;

class Kvector
{
    int *m;
    int len;

public:
    static int total_len;
    Kvector(int sz = 0, int value = 0); // constructor
    Kvector(const Kvector &v);          // copy constructor

    ~Kvector()
    {
        cout << this << " : ~Kvector() \n";
        total_len -= this->len;
        cout << "total length = " << total_len << endl;
        delete[] m;
    }
    void print() const
    {
        for (int i = 0; i < len; i++)
            cout << m[i] << " ";
        cout << endl;
    }
    int size() const { return len; }
};

Kvector::Kvector(int sz, int value) : len(sz)
{
    total_len += sz;
    cout << this << " : Kvector(int, int) \n";
    m = new int[sz + 1];
    for (int i = 0; i < len; i++)
    {
        m[i] = value;
    }
    m[sz] = '\0';
}

Kvector::Kvector(const Kvector &v)
{
    total_len += v.len;
    cout << this << " : Kvector(Kvector&) \n";
    len = v.len;
    m = new int[v.size() + 1];
    for (int i = 0; i < len; i++)
    {
        m[i] = v.m[1];
    }
    m[v.size()] = '\0';
}

int Kvector::total_len = 0;
int main()
{
    Kvector v1(3);
    v1.print();
    const Kvector v2(2, 9);
    v2.print();
    Kvector v3(v2);
    v3.print();

    cout << "total length = " << Kvector::total_len << endl;
    v2.print();
    v3.print();
    cout << "total length = " << Kvector::total_len << endl;

    return 0;
}