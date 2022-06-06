#include <iostream>
using namespace std;

class Kvector
{

public:
    int *m;
    int len;
    //생성자
    Kvector(int sz = 0, int value = 0) : len(sz)
    {
        if (!len)
        {
            m = nullptr;
            return;
        }
        m = new int[len];
        for (int i = 0; i < len; i++)
        {
            m[i] = value;
        }
    }

    //복사생성자
    Kvector(const Kvector &v)
    {
        len = v.len;
        m = new int[len];
        for (int i = 0; i < len; i++)
        {
            m[i] = v.m[i];
        }
    }

    //소멸자
    ~Kvector() { delete[] m; }

    // print
    void print() const
    {
        for (int i = 0; i < len; i++)
        {
            cout << m[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n, a;
    cin >> n >> a;
    const Kvector v(n, a);
    Kvector w(v);

    if (n == 0)
        cout << w.m << endl;
    v.print();
    w.print();

    cout << w.len << endl;
    return 0;
}