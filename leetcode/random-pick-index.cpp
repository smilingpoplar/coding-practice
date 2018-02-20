//
//  random-pick-index
//  https://leetcode.com/problems/random-pick-index/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> _nums;
public:
    Solution(vector<int> nums) {
        _nums = nums;
        srand(time(NULL));
    }
    
    int pick(int target) {        
        int ans = -1;
        int count = 0;
        for (int i = 0; i < _nums.size(); i++) {
            if (_nums[i] == target) {
                count++;
                if (rand() % count == 0) { // 以1/count概率替换已选的
                    ans = i;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main(int argc, const char * argv[]) {
    return 0;
}