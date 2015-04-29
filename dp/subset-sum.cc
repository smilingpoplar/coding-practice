#include <iostream>
#include <vector>

using namespace std;

enum { kNone, kTop, kTopLeft };

// backtrack table: n as left column, m as top row
bool hasSubsetSum(int *a, int n, int m, vector<vector<int>> &bt) {
    bt = vector<vector<int>>(n+1, vector<int>(m+1, kNone)); //
    bool s[n+1][m+1];
    for (int j = 1; j <= m; j++) s[0][j] = false;
    for (int i = 0; i <= n; i++) s[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i-1][j];
            if (s[i-1][j]) bt[i][j] = kTop; //
            if (a[i-1] <= j) {
                s[i][j] |= s[i-1][j - a[i-1]];
                if (s[i-1][j - a[i-1]]) bt[i][j] = kTopLeft; //
            }
        }
    }
    return s[n][m];
}

void printSubset(const vector<vector<int>> &bt, int n, int m, int *a) {
    if (n == 0 || m == 0) return;
    if (bt[n][m] == kTop) {
        printSubset(bt, n-1, m, a);
    } else if (bt[n][m] == kTopLeft) {
        printSubset(bt, n-1, m - a[n-1], a);
        cout << a[n-1] << " ";
    }
}

int main() {
    int a[] = {2, 5, 1, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int m = 8;
    vector<vector<int>> bt;
    cout << hasSubsetSum(a, n, m, bt) << ": ";
    printSubset(bt, n, m, a);
    cout << endl;
    
    m = 4;
    cout << hasSubsetSum(a, n, m, bt) << ": ";
    printSubset(bt, n, m, a);
    cout << endl;

    return 0;
}