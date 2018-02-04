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
        // 包含heights[i]的最大矩形块，要将i往左往右扩展到高度小于它的位置。
        // 用栈找heights[i]右边第一个小于它的位置，若heights[j]<heights[i]将i弹出栈。
        // 对弹出数来说，j是右边小于它的位置，新栈顶是左边小于它的位置，弹出数是个“高峰”。
        // 可计算包含heights[i]的最大矩形面积：h[i]*(j-newTop-1)。
        // 为方便起见，假设heights[]首尾有高度为0的块，变成h[]。
        const int N = heights.size();
        vector<int> h(N + 2); 
        h[0] = h[N + 1] = 0;
        for (int i = 0; i < N; i++) {
            h[i + 1] = heights[i];
        }
        
        int ans = 0;
        stack<int> stack; // 栈中保存坐标
        for (int i = 0; i < N + 2; i++) {
            while (!stack.empty() && h[i] < h[stack.top()]) {
                int top = stack.top();
                stack.pop();
                int newTop = stack.top();
                ans = max(ans, h[top] * (i - newTop - 1));
            }
            stack.push(i);
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
