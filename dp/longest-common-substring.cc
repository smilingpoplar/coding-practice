#include <iostream>
#include <string>

using namespace std;

int lcsLength(const char *s, int m, const char *t, int n, int &lcsLastIndexInS) {
    int lcs[m][n];
    int lcsMax = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] == t[j]) {
                if (i == 0 || j == 0) lcs[i][j] = 1;
                else lcs[i][j] = 1 + lcs[i-1][j-1];
                if (lcs[i][j] > lcsMax) {
                    lcsMax = lcs[i][j];
                    lcsLastIndexInS = i; //
                }
            } else {
                lcs[i][j] = 0;
            }
        }
    }
    return lcsMax;
}

int main() {
    string s = "aa1234bb";
    string t = "c1234d";
    int lcsLastIndexInS;
    int length = lcsLength(s.data(), s.size(), t.data(), t.size(), lcsLastIndexInS);
    cout << length << endl;
    cout << s.substr(lcsLastIndexInS-length+1, length) << endl;
    
    return 0;
}