//
//  contains-duplicate-ii
//  https://leetcode.com/problems/contains-duplicate-ii/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // num=>index
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) != map.end()) {
                if (i - map[nums[i]] <= k) return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,5,4,1,2};
    Solution solution;
    cout << solution.containsNearbyDuplicate(nums, 4);
    
    return 0;
}