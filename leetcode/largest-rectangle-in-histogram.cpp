//
//  largest-rectangle-in-histogram
//  https://leetcode.com/problems/largest-rectangle-in-histogram/
//
//  Created by smilingpoplar on 15/6/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 用栈找“波峰”，当前数小于栈顶时栈顶弹出。
        // 对弹出数来说，弹出数是"波峰"，当前数是右边小于它的数，新栈顶是左边小于它的数。
        // 为方便起见，假设heights[]首尾有高度为0的块，变成h[]。
        const int N = heights.size();
        vector<int> h(N + 2); 
        h[0] = h[N+1] = 0;
        for (int i = 0; i < N; i++) {
            h[i+1] = heights[i];
        }
        
        int ans = 0;
        stack<int> stk; // 栈中保存坐标
        for (int i = 0; i < N + 2; i++) {
            while (!stk.empty() && h[i] < h[stk.top()]) {
                int peak = stk.top(); stk.pop();
                int top = stk.top();
                ans = max(ans, h[peak] * (i - top - 1));
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
