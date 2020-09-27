//
//  largest-rectangle-in-histogram
//  https://leetcode.com/problems/largest-rectangle-in-histogram/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        // 找波峰，对应找下一个更小的数
        h.push_back(0); // 右哨兵
        const int N = h.size();
        int ans = 0;
        stack<int> stk; // 栈中保存坐标
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && h[i] < h[stk.top()]) {
                int peak = stk.top(); stk.pop();
                int left = stk.empty() ? -1 : stk.top();
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
