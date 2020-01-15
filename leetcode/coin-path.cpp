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
        // "两条路径代价相同时，取词典序小的那个"
        // 设dp[i]表示从A[i..]起跳的最小代价，在dp[i]按序尝试i+1,i+2,...,i+B，先找到的最小代价字典序就小。
        // dp[i] = min{ A[i] + dp[i+b] }，1<=b<=B；初始dp[N-1] = 0
        const int N = A.size();
        vector<int> dp(N, INT_MAX);
        dp[N-1] = 0;
        vector<int> next(N, -1); // 记录路径
        for (int i = N - 2; i >= 0; i--) {
            if (A[i] == -1) continue;
            int maxJ = min(i + B, N - 1);
            for (int j = i + 1; j <= maxJ; j++) {
                if (A[j] == -1) continue;
                int cost = A[i] + dp[j];
                if (cost < dp[i]) {
                    dp[i] = cost;
                    next[i] = j;
                }
            }
        }
        
        vector<int> ans;
        // for (p = head; p != NULL; p = p->next)
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
