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
    vector<int> nums;
public:
    Solution(vector<int> nums) : nums(nums) {
        srand(time(NULL));
    }
    
    int pick(int target) {        
        int ans = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                cnt++;
                if (rand() % cnt == 0) { // 以1/cnt概率替换已选的
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
