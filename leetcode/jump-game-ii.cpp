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
        // 每次jump都更新最远可达区间[start,end]，end>=1时到达终点
        const int N = (int)nums.size();
        if (N <= 1) return 0;
        int step = 0;
        int start = 0, end = 0;
        while (true) {
            ++step;
            int oldEnd = end;
            for (int i = start; i <= oldEnd; i++) {
                end = max(end, i + nums[i]);
                if (end >= N - 1) return step;
            }
            if (end == oldEnd) return -1; // 不向前jump

            start = oldEnd + 1;
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    cout << solution.jump(nums);
    
    return 0;
}
