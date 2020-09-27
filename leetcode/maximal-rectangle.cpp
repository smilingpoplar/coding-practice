//
//  maximal-rectangle
//  https://leetcode.com/problems/maximal-rectangle/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 把R行C列的矩阵看作R个以第r行为底的直方图
        if (matrix.empty()) return 0;
        const int R = matrix.size(), C = matrix[0].size();
        int ans = 0;
        vector<int> h(C, 0);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] == '0') h[c] = 0;
                else h[c]++;
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& h) {
        // 同https://leetcode.com/problems/largest-rectangle-in-histogram/
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
    vector<vector<char>> matrix = {
        {1,0,0,1},
        {1,1,1,1},
        {0,1,1,0},
    };
    Solution solution;
    cout << solution.maximalRectangle(matrix);
    
    return 0;
}
