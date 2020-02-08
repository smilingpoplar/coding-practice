//
//  longest-well-performing-interval
//  https://leetcode.com/problems/longest-well-performing-interval/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // >8变为1，否则变为-1，题目为：找子段和>=1最长子段
        // 前缀和+单调栈
        // 假设i<j，要满足presum[j]-presum[i]>=K，需要最大化j-i
        // 1. 固定j最小化i，假设i1<i2<j，presum[i1]<=presum[i2]（注意有＝）
        // i1比i2更好，因为如果(i2,j)满足条件，(i1,j)的和更大、子段更长
        // 所以i2不用保留，presum[]只需保留更小值，用严格单调递减的栈
        // 2. 固定i最大化j，假设i<j1<j2，presum[j2]-presum[i]>=K
        // j1比j2更差，因为(i,j1)子段更短、还可能不满足presum[j1]-presum[i]>=K
        // 所以从右往左找到一个满足条件的j2后，所有j1不用再考虑，i不用再保留，i出栈
        const int N = hours.size();
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + (hours[i] > 8 ? 1 : -1);
        }
        
        // 1 严格单调递减栈
        stack<int> stk;
        for (int i = 0; i <= N; i++) {
            while (stk.empty() || presum[i] < presum[stk.top()]) {
                stk.push(i);
            }
        }
        // 2 从右往左，找presum[j]-stackTop>=K的索引j，找到后i出栈
        int ans = 0;
        for (int j = N; j >= 0; j--) {
            while (!stk.empty() && presum[j] - presum[stk.top()] >= 1) {
                ans = max(ans, j - stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
