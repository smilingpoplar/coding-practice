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
        // 把出现过的数视作索引，把对应索引位置标记为负
        for (int num : nums) {
            int idx = abs(num);
            if (nums[idx-1] > 0) nums[idx-1] *= -1;
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
