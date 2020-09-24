//
//  wildcard-matching
//  https://leetcode.com/problems/wildcard-matching/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    bool isMatch(string s, string p) {
        // 设dp[i][j]表示s[i..]和p[j..]匹配，则
        //   当s[i]==p[j] || p[j]=='?'时，dp[i][j] = dp[i+1][j+1]
        //   当p[j]=='*'时，dp[i][j] = dp[i][j+1] /*匹配0个*/ || dp[i+1][j] /*匹配1个或多个*/
        //   否则，dp[i][j]=false
        // 初始化，s匹配完、p也匹配完，dp[M][N]=true；或者，s匹配完、p剩下的全是*，dp[M][,..]=true
        const int M = s.size(), N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[M][N] = true;
        for (int j = N - 1; j >= 0 && p[j] == '*'; j--) {
            dp[M][j] = true;
        }
        
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (s[i] == p[j] || p[j] == '?') dp[i][j] = dp[i+1][j+1];                 
                else if (p[j] == '*') dp[i][j] = dp[i][j+1] || dp[i+1][j];
                else dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        // 把p看成被*分隔的子串，*可以匹配任意个字符，只要能在s中依次找到被*分隔的子串就能匹配。
        // 匹配时遇到*，说明*前的子串p[..pi-1]已经匹配，要继续在s中搜索*后的子串pi[pi+1..]。
        // 为回溯，记录s当前位置sBt、p中*后的子串位置pBt。
        const int M = s.size(), N = p.size();
        int si = 0, pi = 0;
        int sBt = -1, pBt = -1;
        while (si < M) {
            if (pi < N && (s[si] == p[pi] || p[pi] == '?')) {
                si++;
                pi++;
            } else if (pi < N && p[pi] == '*') { // 记录回溯位置
                sBt = si;
                pBt = ++pi;
            } else if (pBt != -1) { // 虽不能匹配，但有可回溯位置
                si = ++sBt;
                pi = pBt;
            } else {
                return false;
            }
        }
        // s遍历完了p还剩下，p应只剩下*
        while (pi < N && p[pi] == '*') pi++;

        return pi == N;
    }
};
*/

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isMatch("aa", "a*");
    
    return 0;
}
