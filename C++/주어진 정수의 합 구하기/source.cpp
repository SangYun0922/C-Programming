/****************************************************************
 *                                    *
 * Problem : 주어진정수의합구하기                              *
 *                                    *
 ***************************************************************/
 
 /***************************************************************
 *                                                                                  *
 * 국민대학교 소프트웨어융합대학 소프트웨어학부              *
 *                                          20163092 김상윤              *
 ***************************************************************/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0 ; i < T ; i++) {
        int cnt = 0;
        int answer = 0;
        cin >> cnt;
        for (int j = 0 ; j < cnt ; j++) {
            int number = 0;
            cin >> number;
            answer += number;
        }
        cout << answer << endl;
    }
    return 0;
}
