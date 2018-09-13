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
        // 把数x当作下标（1-based），将nums[x-1]标记为负数
        for (int num : nums) {
            int x = abs(num);
            if (nums[x-1] > 0) nums[x-1] = -nums[x-1];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
