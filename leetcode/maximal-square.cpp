//
//  maximal-square
//  https://leetcode.com/problems/maximal-square/
//
//  Created by smilingpoplar on 15/6/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        // 类似https://leetcode.com/problems/maximal-rectangle/
        // 这里求方形的面积，只要在求面积的时候取宽和高的较小值作边长
        // 把M行N列的矩阵看作M个以第i行为底的直方图，直方图从底往上计算高度知道碰见0
        if (matrix.empty()) return 0;
        const int M = (int)matrix.size();
        const int N = (int)matrix[0].size();
        int largestSquare = 0;
        vector<int> h(N, 0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == '0') h[j] = 0;
                else ++h[j];
            }
            largestSquare = max(largestSquare, largestSquareInHistogram(h));
        }
        return largestSquare;
    }
private:
    int largestSquareInHistogram(const vector<int> &h) {
        // 类似https://leetcode.com/problems/largest-rectangle-in-histogram/
        // 包含h[i]的最大矩形块，要将i往左往右扩展到高度小于它的位置
        // 用栈保存h[i]的位置i，从左往右扫描h，比较i处的高度和栈顶top处的高度
        // 若h[i]>=h[top]，将位置i入栈；若h[i]<h[top]，将top出栈，计算包含h[top]的最大矩形块
        // 可以计算是因为已知：往左小于top处高度的位置是下一栈顶位置，往右小于top处高度的位置是i
        
        const int N = (int)h.size();
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
                int length = min(h[top], i - newTop - 1); // 取宽和高的较小值作为边长
                largestArea = max(largestArea, length * length);
            }
        }
        return largestArea;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };
    Solution solution;
    cout << solution.maximalSquare(matrix);

    return 0;
}
