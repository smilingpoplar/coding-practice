//
//  contains-duplicate-iii
//  https://leetcode.com/problems/contains-duplicate-iii/
//
//  Created by smilingpoplar on 15/6/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        // 保持最大长度为k的滑动窗口
        set<int> window; // 记录元素nums[i,j)，j-i<=k
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (j - i > k) {
                window.erase(nums[i]);
                ++i;
            }
            // 看window中是否存在元素x，使nums[j]-t<=x<=nums[j]+t
            // 只需看>=nums[j]-t的最小元素y是否同时<=nums[j]+t
            auto it = window.lower_bound(nums[j] - t);
            if (it != window.end() && *it - t <= nums[j]) return true;
            
            window.insert(nums[j]);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {0, INT_MAX};
    Solution solution;
    cout << solution.containsNearbyAlmostDuplicate(nums, 1, INT_MAX);
    
    return 0;
}
