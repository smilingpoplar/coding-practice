//
//  maximal-rectangle
//  https://leetcode.com/problems/maximal-rectangle/
//
//  Created by smilingpoplar on 15/6/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 把M行N列的矩阵看作M个以第i行为底的直方图，直方图从底往上计算高度直到碰见0
        if (matrix.empty()) return 0;
        const int R = matrix.size();
        const int C = matrix[0].size();
        int ans = 0;
        vector<int> h(C, 0);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] == '0') h[c] = 0;
                else ++h[c];
            }
            ans = max(ans, largestRectangleInHistogram(h));
        }
        return ans;
    }

    int largestRectangleInHistogram(const vector<int> &h) {
        // 同https://leetcode.com/problems/largest-rectangle-in-histogram/
        // 包含h[i]的最大矩形块，要将i往左往右扩展到高度小于它的位置
        // 用栈保存h[i]的位置i，从左到右扫描h数组，比较i处的高度和栈顶top处的高度
        // h[i]>=h[top]就把i入栈，h[i]<h[top]就把top出栈并计算包含h[top]的最大矩形块面积，
        // 可以计算是因为已知：top处往左，高度小于它的位置是新栈顶位置；top处往右，高度小于它的位置是i
        
        const int N = h.size();
        int largestArea = 0;
        vector<int> stack;
        int i = 0;
        while (i <= N) { // i==N是假想的高度为0处
            if (stack.empty() || (i < N && h[i] >= h[stack.back()])) {
                stack.push_back(i);
                ++i;
            } else {
                int top = stack.back();
                stack.pop_back();
                int newTop = stack.empty() ? -1 : stack.back();
                int area = h[top] * (i - newTop - 1);
                largestArea = max(largestArea, area);
            }
        }
        return largestArea;
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
