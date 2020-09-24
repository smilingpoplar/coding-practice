//
//  split-array-with-same-average
//  https://leetcode.com/problems/split-array-with-same-average/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        // 把A分成B和C，不妨设B是较小的那个（1<=k<=N/2）。B和C的均值相等，等于A的整体均值。
        // avgB==avgA, sumB/k==sum/N, sumB==k*sum/N。需要sumB是整数，k需满足(k*sum)%N==0
        // 转变成子集和问题：从A中找k个数，k满足(k*sum)%N==0，且k个数的子集和为k*sum/N

        // 子集和问题是01背包问题
        // 设dp[i][k][v]表示能否从前i个数中取k个数，使子集和等于v。
        // 考虑num，dp[i][k][v] = dp[i-1][k][v]/*不取num*/ || dp[i-1][k-1][v-num] /*取num*/
        // 递推式在i这维只依赖于i-1项，可省掉i这一维。
        // 01背包问题，逆序遍历k和v：dp[k][v] = dp[k][v] || dp[k-1][v-num]
        
        /**
        const int N = A.size();
        int sum = 0;
        for (int num : A) sum += num;
        vector<vector<bool>> dp(N / 2 + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        for (int num : A) { 
            for (int k = N/2; k >= 1; k--) { // 01背包，逆序遍历k和v
                for (int v = sum; v >= num; v--) {
                    dp[k][v] = dp[k][v] || dp[k-1][v-num];
                }
            }
        }

        for (int k = 1; k <= N / 2; k++) {
            if (k * sum % N == 0 && dp[k][k * sum / N]) return true;
        }
        return false;
        */
        
        // 优化：这里num在范围[0,10000]，和值v较大，用数组dp[i][k][v]浪费空间。
        // 改用vector<vector<unordered_set<int>>> sums;
        // sums[i][k]表示从前i个数中取k个数、能达到的和值集，初始sums[0][0] = {0}
        // sums[i][k] = sums[i-1][k] /*不取A[i]*/ ∪ (sums[i-1][k-1] + A[i]) /*取A[i]*/
        // 递推式在i这维只依赖i-1项，可省掉i这维。01背包问题，逆序遍历k：
        // sums[k] = sums[k] ∪ (sums[k-1] + A[i])
        
        const int N = A.size();
        int sum = 0;
        for (int num : A) sum += num;
        if (!canSplit(sum, N)) return false; // 提早返回
        
        vector<unordered_set<int>> sums(N / 2 + 1);
        sums[0] = {0};
        for (int num : A) {
            for (int k = N / 2; k >= 1; k--) { // 01背包，逆序遍历
                for (int s : sums[k-1]) {
                    sums[k].insert(s + num);
                }
            }
        }
        
        for (int k = 1; k <= N / 2; k++) {
            if (k * sum % N == 0 && sums[k].count(k * sum / N)) return true;
        }
        return false;
    }
    
    bool canSplit(int sum, int N) {
        for (int k = 1; k <= N / 2; k++) {
            if (k * sum % N == 0) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
