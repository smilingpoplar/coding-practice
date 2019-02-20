//
//  trapping-rain-water
//  https://leetcode.com/problems/trapping-rain-water/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        // 某bar上的储水：min(它左侧（含）最高的bar高，它右侧（含）最高的bar高) - 它自己的bar高
        const int N = height.size();
        vector<int> leftMax(N, 0);
        leftMax[0] = height[0];
        for (int i = 1; i < N; i++) {
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        vector<int> rightMax(N, 0);
        rightMax[N-1] = height[N-1];
        for (int i = N - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }
        
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};
*/

class Solution {
public:
    int trap(vector<int>& height) {
        // 用栈找波谷
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int valley = stk.top(); stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                // "波谷"的右i和左left都比它高，贡献一个水层
                int w = i - left - 1;
                int h = min(height[i], height[left]) - height[valley];
                ans += w * h;
            }
            stk.push(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    cout << solution.trap(height);
    
    return 0;
}
