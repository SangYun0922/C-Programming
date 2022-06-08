#include <iostream>
using namespace std;
#define N 3

class Kvector
{
protected:
    int *m;
    int len;

public:
    Kvector(int sz = 0, int value = 0) : len(sz)
    {
        if (!sz)
        {
            m = NULL;
            return;
        }
        m = new int[sz];
        for (int i = 0; i < sz; i++)
            m[i] = value;
    }
    Kvector(const Kvector &v)
    {
        len = v.len;
        if (!len)
        {
            m = NULL;
            return;
        }
        m = new int[len];
        for (int i = 0; i < len; i++)
            m[i] = v.m[i];
    }
    ~Kvector()
    {
        delete[] m;
    }
    void print() const
    {
        for (int i = 0; i < len; i++)
            cout << m[i] << " ";
        cout << endl;
    }
    friend ostream &operator<<(ostream &os, const Kvector &v);
};

ostream &operator<<(ostream &os, const Kvector &v)
{
    for (int i = 0; i < v.len; i++)
        os << v.m[i] << " ";
    return os;
}

class Avector : public Kvector
{
    char table[N];

public:
    Avector(int sz = 0, int v = 0, const char *t = "abc") : Kvector(sz, v)
    {
        for (int i = 0; i < N; i++)
            table[i] = t[i];
    }
    void setTable(const char *t)
    {
        for (int i = 0; i < N; i++)
            table[i] = t[i];
    }
    friend ostream &operator<<(ostream &os, const Avector &v);
};

ostream &operator<<(ostream &os, const Avector &v)
{
    for (int i = 0; i < v.len; i++)
        os << v.table[v.m[i] % N] << " ";
    return os;
}

int main()
{
    int a, b;
    char s[10] = "str", t[10] = "def";
    cin >> a >> b;

    Avector v1(a, b, s);
    v1.print();
    Avector v2(v1);
    v2.print();
    v1.setTable(t);
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    return 0;
}
