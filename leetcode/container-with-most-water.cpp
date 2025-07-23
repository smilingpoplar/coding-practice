//
//  container-with-most-water
//  https://leetcode.com/problems/container-with-most-water/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 贪心法：首尾两指针，向内移动矮的那个
        int i = 0, j = (int)height.size() - 1;
        int ans = 0;
        while (i < j) {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> height = {3, 2, 3};
    Solution solution;
    cout << solution.maxArea(height);

    return 0;
}
