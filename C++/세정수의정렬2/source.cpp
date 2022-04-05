/****************************************************************
 *                                    *
 * Problem : 세정수의정렬2                    *
 *                                    *
 ***************************************************************/
 
 /***************************************************************
 *                                                                                  *
 * 국민대학교 소프트웨어융합대학 소프트웨어학부              *
 *                                          20163092 김상윤              *
 ***************************************************************/
#include <iostream>
using namespace std;

void list3Numbers(int a, int b, int c);
int main(void) {
    int numTestCases;
    int a, b, c;
    
    cin >> numTestCases;
    
    for(int i=0; i< numTestCases; i++)
    {
        cin >> a >> b >> c;
        list3Numbers( a, b, c );
    }
    
    return 0;
}
void list3Numbers(int a, int b, int c)
{
    if(a <= b)
    {
        if(b <= c)
            cout << a << " " << b << " " << c << endl;
        else
        {
            if(a <= c)
                cout << a << " " << c << " " << b << endl;
            else
                cout << c << " " << a << " " << b << endl;
        }
    }
    else
    {
        if(c <= b)
            cout << c << " " << b << " " << a << endl;
        else
        {
            if(a <= c)
                cout << b << " " << a << " " << c << endl;
            else
                cout << b << " " << c << " " << a << endl;
        }
    }
}
