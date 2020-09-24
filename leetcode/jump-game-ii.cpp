//
//  jump-game-ii
//  https://leetcode.com/problems/jump-game-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // bfs分层遍历，记录最远可达farthest
        const int N = nums.size();
        if (N <= 1) return 0;

        int farthest = 0, ans = 0;
        for (int i = 0; i <= farthest; ) {
            ans++;            
            for (int sofar = farthest; i <= sofar; i++) {
                farthest = max(farthest, i + nums[i]);
                if (farthest >= N - 1) return ans;
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
