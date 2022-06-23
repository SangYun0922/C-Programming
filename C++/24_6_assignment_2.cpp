#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <string>

using namespace std;

template <typename T>
void print_container(const T &container, string s = "")
{
    cout << s << "(" << container.size() << ") ";
    auto it = container.begin();
    for (; it != container.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    string a[3] = {"0x1A", "0x1C", "0x20"};

    deque<string> d(&a[0], &a[3]);
    d.push_front("0x19");
    print_container(d, "d= ");

    vector<string> v(&a[0], &a[3]);
    v.insert(v.begin(), "0x19");
    print_container(v, "v= ");

    list<string> l(&a[0], &a[3]);
    list<string>::iterator it = l.begin();
    it++;
    it++;
    l.insert(it, "0x1D");
    print_container(l, "l= ");

    return 0;
}
