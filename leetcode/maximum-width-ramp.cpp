//
//  maximum-width-ramp
//  https://leetcode.com/problems/maximum-width-ramp/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        // 找相距最远的两个递增数
        const int N = A.size();
        stack<int> stk; // 栈底固定为A[0]的递减栈
        for (int i = 0; i < N; i++) {
            if (stk.empty() || A[i] < A[stk.top()]) {
                stk.push(i);
            }
        }
        // 在从右往左A[j]与栈顶比较
        int ans = 0;
        for (int j = N - 1; j >= 0; j--) {
            while (!stk.empty() && A[j] >= A[stk.top()]) {
                ans = max(ans, j - stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        const int N = A.size();
        multimap<int, int> mp; // num=>idx
        for (int i = 0; i < N; i++) {
            mp.insert({A[i], i});
        }
        
        int minIdx = INT_MAX, ans = 0;
        for (auto &e : mp) { // 按值递增遍历
            int idx = e.second;
            ans = max(ans, idx - minIdx);
            minIdx = min(minIdx, idx);
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
