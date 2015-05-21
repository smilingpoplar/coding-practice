//
//  trapping-rain-water.cpp
//  https://leetcode.com/problems/trapping-rain-water/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 某个bar上方能存得水等于：max(0, min(它左侧最高的bar高，它右侧最高的bar高) - 它自己的bar高)
        const int N = (int)height.size();
        vector<int> leftMax(N, 0);
        for (int i = 1; i < N; ++i) {
            leftMax[i] = max(height[i - 1], leftMax[i - 1]);
        }
        
        vector<int> rightMax(N, 0);
        for (int i = N - 2; i >= 0; --i) {
            rightMax[i] = max(height[i + 1], rightMax[i + 1]);
        }
        
        int water = 0;
        for (int i = 0; i < N; ++i) {
            water += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }

        return water;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    cout << solution.trap(height);
    
    return 0;
}
