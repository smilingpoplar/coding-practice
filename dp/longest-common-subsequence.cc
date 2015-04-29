#include <iostream>
#include <vector>

using namespace std;

enum { kNone, kLeft, kTop, kTopLeft };

// backtrack table: s as left column, t as top row
int lcsLength(const char *s, int m, const char *t, int n, vector<vector<int>> &bt) {
    bt = vector<vector<int>>(m+1, vector<int>(n+1, kNone)); //
    int lcs[m+1][n+1];
    for (int j = 0; j <= n; j++) lcs[0][j] = 0;
    for (int i = 0; i <= m; i++) lcs[i][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];
                bt[i][j] = kTopLeft; //
            } else {
                lcs[i][j] = max( lcs[i][j-1], lcs[i-1][j] );
                if (lcs[i][j-1] < lcs[i-1][j]) bt[i][j] = kTop; //
                else bt[i][j] = kLeft; //
            }
        }
    }
    return lcs[m][n];
}

void lcsPrint(const vector<vector<int>> &bt, int m, int n, const char *s) {
    if (m == 0 || n == 0) return;
    if (bt[m][n] == kTopLeft) {
        lcsPrint(bt, m-1, n-1, s);
        cout << s[m-1] << " ";
    } else {
        if (bt[m][n] == kTop) {
            lcsPrint(bt, m-1, n, s);
        } else if (bt[m][n] == kLeft) {
            lcsPrint(bt, m, n-1, s);
        }
    }
}

int main() {
    string s = "hello";
    string t = "lleho";
    vector<vector<int>> bt;
    cout << lcsLength(s.data(), s.size(), t.data(), t.size(), bt) << ": ";
    lcsPrint(bt, s.size(), t.size(), s.data());
    
    return 0;
}