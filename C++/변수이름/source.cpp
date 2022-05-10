#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int T;
    cin >> T;
    for (int i = 0 ; i < T ; i++) {
        char word[256];
        std::fill_n(word, 256, 0);
        int res = 1;
        cin >> word;
        if (word[0] < 'A' || (word[0] > 'Z' && word[0] < '_') || (word[0] > '_' && word[0] < '`') || (word[0] > 'z') )
            res = 0;
        else {
            int j = 1;
            while (word[j] != 0) {
                if (word[j] < '0' || (word[j] > '9' && word[j] < 'A') || (word[0] > 'Z' && word[0] < '_') || (word[0] > '_' && word[0] < '`') || (word[j] > 'z')) {
                    res = 0;
                }
                j++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
