//
//  monotonic-stack
//  NC157 单调栈
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> foundMonotoneStack(vector<int>& nums) {
        // 找波峰
        const int N = nums.size();
        stack<int> stk;
        vector<vector<int>> ans(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && nums[i] <= nums[stk.top()]) {
                stk.pop();
            }
            ans[i][0] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while (!stk.empty()) {
            stk.pop();
        }
        // 从右往左再来一遍
        for (int i = N - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] <= nums[stk.top()]) {
                stk.pop();
            }
            ans[i][1] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        return ans;
    }
};