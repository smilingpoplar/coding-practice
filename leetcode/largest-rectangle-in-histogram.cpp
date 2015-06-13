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
    int largestRectangleArea(vector<int>& h) {
        // 包含h[i]的最大矩形块，要将i往左往右扩展到高度小于它的位置
        // 用栈保存h[i]的位置i，从左到右扫描h数组，比较i处的高度和栈顶top处的高度
        // h[i]>=h[top]就把i入栈，h[i]<h[top]就把top出栈并计算包含h[top]的最大矩形块面积，
        // 可以计算是因为已知：top处往左，高度小于它的位置是新栈顶位置；top处往右，高度小于它的位置是i

        const int N = (int)h.size();
        int largestArea = 0;
        vector<int> stack;
        int i= 0;
        while (i <= N) {
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
    vector<int> height = {2,1,5,6,2,3};
    Solution solution;
    cout << solution.largestRectangleArea(height);
    
    return 0;
}
