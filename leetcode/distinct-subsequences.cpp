//
//  distinct-subsequences
//  https://leetcode.com/problems/distinct-subsequences/
//
//  Created by smilingpoplar on 15/5/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // 动态规划，设f(i,j)表示s[0,i)中子序列t[0,j)的个数 (0<=i<=M, 0<=j<=N)
        // 若s[i-1]==t[j-1]，f(i,j) = f(i-1,j-1)/*使用s[i-1]*/ + f(i-1,j)/*不使用s[i-1]*/
        // 若s[i-1]!=t[j-1]，f(i,j) = f(i-1,j)
        // 初值：f(i,0)=1，f(0,j>0)=0
        // 递推式中第i项仅由第i-1项决定，因此在i循环中可降维：
        // 若s[i-1]==t[j-1]，f(j)=f(j-1)+f(j) // 要逆序遍历才能保证下一循环时f(j-1)的值没被覆盖
        // 若s[i-1]!=t[j-1]，f(j)=f(j)
        // 即仅当s[i-1]==t[j-1]时，f(j)+=f(j-1) // 逆序遍历
        const int M = (int)s.size();
        const int N = (int)t.size();
        vector<int> f(N + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= M; i++) {
            for (int j = N; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    f[j] += f[j - 1];
                }
            }
        }
        return f[N];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.numDistinct("rabbbit", "rabbit");
    
    return 0;
}
