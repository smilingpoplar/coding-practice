//
//  longest-well-performing-interval
//  https://leetcode.com/problems/longest-well-performing-interval/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // >8变为1，否则变为-1，题目为：找子段和>0最长子段
        // 配合presum数组，变成找相距最远的两个递增数
        // 同https://leetcode.com/problems/maximum-width-ramp/
        const int N = hours.size();
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + (hours[i] > 8 ? 1 : -1);
        }
        
        stack<int> stk; // 栈底固定为presum[0]的递减栈
        for (int i = 0; i <= N; i++) {
            while (stk.empty() || presum[i] < presum[stk.top()]) {
                stk.push(i);
            }
        }
        // 在从右往左A[j]与栈顶比较
        int ans = 0;
        for (int j = N; j >= 0; j--) {
            while (!stk.empty() && presum[j] - presum[stk.top()] > 0) {
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
