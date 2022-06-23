#include <iostream>
using namespace std;

class A
{

public:
    static int numberOfObjectsA;

    A()
    {
        numberOfObjectsA++;
    }

    ~A()
    {
        numberOfObjectsA--;
    }
};

int A::numberOfObjectsA = 0;

int main(void)
{
    A a1[3], *p; //포인터가 선언된다고 해서 A의 오브젝트가 만들어지지는 않는다.
    cout << A::numberOfObjectsA << endl;
    int n;
    cin >> n;
    cout << A::numberOfObjectsA << endl;
    p = new A[n];
    cout << a1[0].numberOfObjectsA << endl;
    delete p;
    cout << A::numberOfObjectsA << endl;
    return 0;
}