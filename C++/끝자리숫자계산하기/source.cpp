/****************************************************************
 *                                    *
 * Problem : 끝자리숫자계산하기                    *
 *                                    *
 ***************************************************************/
 
 /***************************************************************
 *                                                                                  *
 * 국민대학교 소프트웨어융합대학 소프트웨어학부              *
 *                                          20163092 김상윤              *
 ***************************************************************/
#include <iostream>
using namespace std;

int main(void) {
    int numTestCases;
    
    cin >> numTestCases;
    
    for(int i=0; i< numTestCases; i++)
    {
        int cnt;
        int temp = 1;
        cin >> cnt ;
        for (int j = 0; j < cnt ; j++) {
            int num;
            cin >> num;
            temp *= num % 10;
            temp %= 10;
        }
        cout << temp << endl;
    }
    
    return 0;
}
