//
//  find-all-numbers-disappeared-in-an-array
//  https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){
        // 把出现过的数当作索引，把对应索引位置变为负
        for (int num : nums) {
            int idx = abs(num);
            nums[idx-1] = -abs(nums[idx-1]);
        }
        vector<int> ans;
        for (int i = 1; i <= nums.size(); i++) {
            if (nums[i-1] > 0) ans.push_back(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
