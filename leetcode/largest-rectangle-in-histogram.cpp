//
//  largest-rectangle-in-histogram
//  https://leetcode.com/problems/largest-rectangle-in-histogram/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 用栈找“波峰” <=> 找下一个更小的数
        // 弹出数是"波峰"，当前数是右边小于它的数，新栈顶是左边小于它的数。

        // 为方便起见，heights[]首尾加上高度为0的哨兵块，变为h[]
        vector<int> h(heights.size() + 2, 0);
        const int N = h.size();
        for (int i = 1; i < N - 1; i++) {
            h[i] = heights[i-1];
        }

        int ans = 0;
        stack<int> stk; // 栈中保存坐标
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && h[i] < h[stk.top()]) {
                int peak = stk.top(); stk.pop();
                int left = stk.top();
                ans = max(ans, h[peak] * (i - left - 1));
            }
            stk.push(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> height = {2,1,5,6,2,3};
    Solution solution;
    cout << solution.largestRectangleArea(height);
    
    return 0;
}
