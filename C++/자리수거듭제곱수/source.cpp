/****************************************************************
 *                                    *
 * Problem : 자리수거듭제곱수                    *
 *                                    *
 ***************************************************************/
 
 /***************************************************************
 *                                                                                  *
 * 국민대학교 소프트웨어융합대학 소프트웨어학부              *
 *                                          20163092 김상윤              *
 ***************************************************************/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(void) {
    int numTestCases;
    
    cin >> numTestCases;
    
    for(int i=0; i< numTestCases; i++)
    {
        int num, temp, result;
        result = 0;
        cin >> num;
        string len = to_string(num);
        temp = num;
        for (int i = 0 ; i < len.length() ; i++) {
            result += pow((temp%10), len.length());
            temp = temp/10;
        }
        if (num == result)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
