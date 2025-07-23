//
//  longest-common-subsequence.nkw
//

#include <iostream>

using namespace std;

class Solution {
public:
    string LCS(string s1, string s2) {
        // 设dp[i][j]表示s1[i..]和s2[j..]的LCS长
        // s1[i]==s2[j]，dp[i][j] = 1 + dp[i+1][j+1]
        // s1[i]!=s2[j]，dp[i][j] = max(dp[i+1][j], dp[i][j+1])
        const int M = s1.size();
        const int N = s2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        vector<vector<int>> d(M + 1, vector<int>(N + 1, 0));

        int maxlen = 0, fromI = M, fromJ = N;
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                    d[i][j] = 1;
                } else if (dp[i + 1][j] > dp[i][j + 1]) {
                    dp[i][j] = dp[i + 1][j];
                    d[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j + 1];
                    d[i][j] = 3;
                }
                if (dp[i][j] > maxlen) {
                    maxlen = dp[i][j];
                    fromI = i, fromJ = j;
                }
            }
        }

        if (maxlen == 0) return "-1";
        return subseq(fromI, fromJ, d, s1);
    }

    string subseq(int i, int j, const vector<vector<int>>& d, const string& s1) {
        string ans;
        if (d[i][j] == 1) {
            ans = s1[i] + subseq(i + 1, j + 1, d, s1);
        } else if (d[i][j] == 2) {
            ans = subseq(i + 1, j, d, s1);
        } else if (d[i][j] == 3) {
            ans = subseq(i, j + 1, d, s1);
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
