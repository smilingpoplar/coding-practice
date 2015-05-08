//
//  jump-game
//  https://leetcode.com/problems/jump-game/
//
//  Created by smilingpoplar on 15/5/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // nums中的数表示最大可跳距离，要能跳到N-1，只要能跳到>=N-1的位置即可
        const int N = (int)nums.size();
        int reach = 0;
        for (int i = 0; i <= reach; i++) {
            reach = max(reach, i + nums[i]);
            if (reach >= N - 1) return true;
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> nums = {3,2,1,0,4};
    cout << solution.canJump(nums);
    
    return 0;
}
