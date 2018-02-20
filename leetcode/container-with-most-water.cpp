//
//  container-with-most-water
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
        // 首尾两指针，向内移动矮的那个
        // 因为容器高度由短的决定，向内移动高的那个则容器高度不变、宽度更小，结果更差
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> height = {3, 2, 3};
    Solution solution;
    cout << solution.maxArea(height);
    
    return 0;
}
