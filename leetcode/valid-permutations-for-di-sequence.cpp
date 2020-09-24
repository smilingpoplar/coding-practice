//
//  valid-permutations-for-di-sequence
//  https://leetcode.com/problems/valid-permutations-for-di-sequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numPermsDISequence(string S) {
        // 设dp[i][j]表示[0..i]的排列、结尾是j时的DI排列数
        // dp[i][j]与子问题dp[i-1][]有什么关系？
        // 考虑某排列（如201），它跟比它长1的、分别以0,1,2,3结尾的排列（3120,3021,3012,2013）可以建立一一映射，比如：
        //  1) 在201后添上>结尾1的数，比如添上2（=>2012），然后把原排列中>=新添数的都加上1（=>3012），
        //  这就构成结尾的*I排列*；过程反过来，3012去掉结尾2（=>301），然后把剩下排列中>=去掉数的都减去1（=>201）。
        //  若dp[i][j]的结尾是I排列（如3012=>201），dp[i][j]=sum(dp[i-1][<j])
        //  2) 在201后添上<=结尾1的数，比如添上1（=>2011），然后把原排列中>=新添数的都加上1（=>3021），
        //  这就构成结尾的*D排列*；过程反过来，3021去掉结尾1（=>302），然后把剩下排列中>=去掉数的都减去1（=>201）。
        //  若dp[i][j]的结尾是D排列（如3021=>201），dp[i][j]=sum(dp[i-1][>=j])
        // 初始dp[0][0]=1。在i维上只依赖i-1项，可省掉i这维，i仍从左往右遍历。
        // 第j维由dp[i-1][<j]、dp[i-1][>=j]决定的遍历顺序冲突，要用临时变量ndp[j]。
        
        const int MOD = 1e9 + 7;
        const int N = S.size(); // [0..N]的排列
        vector<int> dp(N + 1, 0);
        dp[0] = 1; // i==0
        
        for (int i = 1; i <= N; i++) {
            vector<int> ndp(N + 1, 0);
            for (int j = 0; j <= i; j++) {
                if (S[i-1] == 'I') {
                    for (int k = 0; k < j; k++) {
                        ndp[j] = (ndp[j] + dp[k]) % MOD;
                    }
                } else {
                    for (int k = j; k < i; k++) {
                        ndp[j] = (ndp[j] + dp[k]) % MOD;
                    }
                }
            }
            swap(dp, ndp);
        }
        
        int ans = 0;
        for (int j = 0; j <= N; j++) {
            ans = (ans + dp[j]) % MOD;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
