/****************************************************************
 *                                    *
 * Problem : 시침과분침사이각구하기                     *
 *                                    *
 ***************************************************************/
 
 /***************************************************************
 *                                                                                  *
 * 국민대학교 소프트웨어융합대학 소프트웨어학부              *
 *                                          20163092 김상윤              *
 ***************************************************************/
// 시침은 1시간 마다 30도 & 1분마다 0.5도 움직임
// 분침은 1분마다 6도 움직임
#include <iostream>
#include <cmath>
using namespace std;

int angleClock(int h, int m);
int main(void) {
    int t;
    int h, m;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> h >> m;
        cout << angleClock( h, m ) << endl;
    }
    return 0;
}

int angleClock(int h, int m) {
    float h_angle, m_angle;
    float answer;
    h_angle = (h * 30) + (m * 0.5);
    m_angle = (m * 6);
    answer = h_angle - m_angle;
    return min(abs(answer), 360 - abs(answer));
}
