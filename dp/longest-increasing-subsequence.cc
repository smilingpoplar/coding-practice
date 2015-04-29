#include <iostream>
#include <string>
#include <vector>

using namespace std;

// pre: previous element index
int longestIncreasingSubsequence(const char *s, int n, vector<int> &pre, int &lisMaxIndex) {
    pre = vector<int>(n); //
    for (int i = 0; i < n; i++) pre[i] = i; //
    vector<int> lis(n, 1);
    int lisMax = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] >= s[j]) {
                if (lis[j]+1 > lis[i]) {
                    lis[i] = lis[j]+1;
                    pre[i] = j; //
                    if (lis[i] > lisMax) {
                        lisMax = lis[i];
                        lisMaxIndex = i; //
                    }
                }
            }
        }
    }
    return lisMax;
}

void lisPrint(const vector<int> &pre, int index, const char *s) {
    if (index != pre[index]) lisPrint(pre, pre[index], s);
    cout << s[index];
}

int main() {
    string s = "41521324151";
    vector<int> pre;
    int lisMaxIndex;
    cout << longestIncreasingSubsequence(s.data(), s.size(), pre, lisMaxIndex) << endl;
    lisPrint(pre, lisMaxIndex, s.data());
    return 0;
}