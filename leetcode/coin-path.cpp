//
//  coin-path
//  https://leetcode.com/problems/coin-path/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        // "当有两条等长的最小代价路径时，取词典序小的那个"，即当存在[x..i..y]和[x..j..y]时，取[x..i..y]
        // 要满足这个条件，只需dp从后往前进行，即定义dp[i]表示从A[i]到A[n-1]的最小代价，
        // 并在dp[i]按序尝试i+1,i+2,...,i+B，先找到的最小代价就满足字典序小
        // dp[i] = min(dp[i], dp[i+x] + A[i])，1<=x<=B
        // 初始dp[N-1] = 0
        const int N = A.size();
        vector<int> dp(N, INT_MAX);
        dp[N-1] = 0;
        vector<int> next(N, -1);
        for (int i = N - 2; i >= 0; i--) {
            if (A[i] == -1) continue;
            int minJ = i + 1, maxJ = min(i + B, N - 1);
            for (int j = minJ; j <= maxJ; j++) {
                if (A[j] == -1) continue;
                int cost = dp[j] + A[i];
                if (cost < dp[i]) {
                    dp[i] = cost;
                    next[i] = j;
                }
            }
        }
        
        // 找路径
        vector<int> ans;
        for (int i = 0; i != -1; i = next[i]) {
            ans.push_back(i + 1); // 1-indexed
            if (i == N - 1) return ans;
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
