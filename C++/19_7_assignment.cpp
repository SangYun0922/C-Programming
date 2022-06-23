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
    int &operator[](int idx) { return m[idx]; }             // const 키워드를 붙여서 만들 수도 있다. 이것은, v1이 const 객체일때, v2[0] = v1[2] 를 하려고 하면 해당 함수가 실행 될 수 없다. 따라서 const가 붙은 함수를 써주어야 한다.
    const int &operator[](int idx) const { return m[idx]; } // 또한 해당 리턴되는 객체는 const 타입이기때문에 앞에 const를 붙여주어야 한다.
};

Kvector::Kvector(int sz, int value) : len(sz)
{
    cout << this << " : Kvector(int, int)" << endl;
    m = new int[len];
    for (int i = 0; i < len; i++)
    {
        m[i] = value;
    }
}

Kvector::Kvector(Kvector &v)
{
    cout << this << " : Kvector(Kvector&)" << endl;
    len = v.len;
    m = new int[len];
    for (int i = 0; i < len; i++)
    {
        m[i] = v.m[i];
    }
}

Kvector &Kvector::operator=(const Kvector &v)
{
    delete[] m; // 메모리 누수가 발생할 것을 방지해준다.
    len = v.len;
    m = new int[len];
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
        int i = 0;
        while (i == v.len)
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

bool operator!=(const Kvector &v, const Kvector &w) //굳이 friend로 선언하지 않아도 된다! 왜냐하면 멤버변수들을 쓰지 않기 때문이다.
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

    const Kvector v4(3, 5);
    v3[2] = v4[1];
    v3.print();
}