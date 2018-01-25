//
//  container-with-most-water.cpp
//  https://leetcode.com/problems/container-with-most-water/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 假设现在计算了h[l,r]部分的面积，且h[l]<=h[r]，下一步可以把指针l往右移，
        // 因为所有以l为端点的部分（如h[l,r-1], h[l,r-2]...）的面积都小于h[l,r]（长度：< 高度：<=）
        // 由此，可用两端夹逼法，高度较小的指针往里移动
        int l = 0;
        int r = (int)height.size() - 1;
        int maxArea = 0;
        while (l < r) {
            int area = (r - l) * min(height[l], height[r]);
            maxArea = max(maxArea, area);
            if (height[l] <= height[r]) ++l;
            else --r;
        }
        return maxArea;
    }
    
    /* 简单解法超时
    int maxArea(vector<int>& height) {
        const int N = (int)height.size();
        int maxArea = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int area = min(height[i], height[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
    */
};

int main(int argc, const char * argv[]) {
    vector<int> height = {3, 2, 3};
    Solution solution;
    cout << solution.maxArea(height);
    
    return 0;
}
