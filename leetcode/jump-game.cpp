//
//  jump-game
//  https://leetcode.com/problems/jump-game/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int farthest = 0;
        for (int i = 0; i <= farthest; i++) {
            farthest = max(farthest, i + nums[i]);
            if (farthest >= N - 1) return true;
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
