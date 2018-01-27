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
        set<long> win; // 保持长度<=k的滑动窗口
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            // 考虑插入nums[j]之前
            if (j - i > k) {
                win.erase(nums[i]);
                i++;
            }
            // win中是否存在x，使nums[j]-x<=t且x-nums[j]<=t，nums[j]-t<=x<=nums[j]+t
            // 只要找>=nums[j]-t的数，看它是否满足<=nums[j]+t
            auto it = win.lower_bound((long)nums[j] - t);
            if (it != win.end() && *it <= (long)nums[j] + t) return true;
            
            win.insert(nums[j]);            
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
