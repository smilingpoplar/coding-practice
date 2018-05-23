//
//  find-all-duplicates-in-an-array
//  https://leetcode.com/problems/find-all-duplicates-in-an-array/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        // 把出现过的数当作索引，把对应索引位置变为负
        for (int num : nums) {
            int idx = abs(num);
            if (nums[idx-1] < 0) {
                ans.push_back(idx);
            }                
            nums[idx-1] = -nums[idx-1];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
