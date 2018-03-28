//
//  max-consecutive-ones-ii
//  https://leetcode.com/problems/max-consecutive-ones-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // 扩展：滑动窗口中至多k个0。无限流的情况，用个队列保存各0的下标。
        const int k = 1;
        int ans = 0;
        queue<int> zeroIdx;
        for (int winStart = 0, i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroIdx.push(i);
            
            while (zeroIdx.size() > k) {
                winStart = zeroIdx.front() + 1;
                zeroIdx.pop();
            }
            ans = max(ans, i - winStart + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
