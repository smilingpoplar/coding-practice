//
//  jump-game-ii
//  https://leetcode.com/problems/jump-game-ii/
//
//  Created by smilingpoplar on 15/5/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // 按bfs分层遍历思路，记录可达的最远索引maxIdx
        const int N = nums.size();
        if (N <= 1) return 0;
        int maxIdx = 0, i = 0;
        int level = 0;
        while (i <= maxIdx) {
            level++;
            int levelMaxIdx = maxIdx;
            for (; i <= levelMaxIdx; i++) {
                maxIdx = max(maxIdx, i + nums[i]);
                if (maxIdx >= N - 1) return level;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    cout << solution.jump(nums);
    
    return 0;
}
