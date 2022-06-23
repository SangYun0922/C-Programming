#include <iostream>
using namespace std;

#define N 3

class Kvector
{
protected:
    int *m;
    int len;

public:
    Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector &v);
    ~Kvector();
    void print() const;
    void clear();
    int size();
    Kvector &operator=(const Kvector &v);
    friend bool operator==(const Kvector &v, const Kvector &w);
    friend bool operator!=(const Kvector &v, const Kvector &w);
    int &operator[](int idx);
    const int &operator[](int idx) const;
    friend ostream &operator<<(ostream &os, const Kvector &v);
};

Kvector::Kvector(int sz, int value) : len(sz)
{
    cout << this << " : Kvector(" << sz << "," << value << ")\n";
    if (!len)
    {
        m = NULL;
        return;
    }
    m = new int[len];
    for (int i = 0; i < len; i++)
    {
        m[i] = value;
    }
}

Kvector::Kvector(const Kvector &v)
{
    cout << this << " : Kvector(* " << &v << ")\n";
    len = v.len;
    if (!len)
    {
        m = NULL;
        return;
    }
    m = new int[v.len];
    for (int i = 0; i < v.len; i++)
    {
        m[i] = v.m[i];
    }
}

Kvector::~Kvector()
{
    cout << this << " : ~Kvector() \n";
    delete[] m;
}

void Kvector::print() const
{
    for (int i = 0; i < len; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}

void Kvector::clear()
{
    delete[] m;
    m = NULL;
    len = 0;
}

int Kvector::size()
{
    return len;
}

Kvector &Kvector::operator=(const Kvector &v)
{
    delete[] m;
    len = v.len;
    for (int i = 0; i < len; i++)
    {
        m[i] = v.m[i];
    }
    return *this;
}

bool operator==(const Kvector &v, const Kvector &w)
{
    if (v.len == w.len)
    {
        for (int i = 0; i < v.len; i++)
        {
            if (v.m[i] != w.m[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const Kvector &v, const Kvector &w)
{
    return !(v == w);
}

int &Kvector::operator[](int idx) { return m[idx]; }
const int &Kvector::operator[](int idx) const { return m[idx]; }

ostream &operator<<(ostream &os, const Kvector &v)
{
    for (int i = 0; i < v.len; i++)
    {
        os << v.m[i] << " ";
    }
    return os;
}

class Avector : public Kvector
{
    char table[N];

public:
    Avector(int sz = 0, int v = 0, const char *t = "abc");
    void setTable(const char *t);
    friend ostream &operator<<(ostream &os, const Avector &v);
};

Avector::Avector(int sz, int v, const char *t) : Kvector(sz, v)
{
    cout << this << " : Avector(" << sz << "," << v << "," << t << ")\n";
    for (int i = 0; i < N; i++)
    {
        table[i] = t[i];
    }
}

void Avector::setTable(const char *t)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = t[i];
    }
}

ostream &operator<<(ostream &os, const Avector &v)
{
    for (int i = 0; i < v.len; i++)
    {
        os << v.table[v.m[i] % N] << " ";
    }
    return os;
}

int main(int argc, char *argv[])
{
    Avector v1(3);
    v1.print();
    Avector v2(2, 1, "xyz");
    v2.print();
    Avector v3(v2);
    v3.print();
    cout << "v1 == v2 " << (v1 == v2) << endl;
    cout << "v3 == v2 " << (v3 == v2) << endl;

    v3 = v2 = v1;
    cout << "v1 : " << v1 << endl;
    v1.print();
    cout << "v2 : " << v2 << endl;
    v2.print();
    cout << "v3 : " << v3 << endl;
    v3.print();

    cout << "v3 != v2 " << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}