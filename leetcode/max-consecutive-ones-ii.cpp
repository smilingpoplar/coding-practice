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
        // 扩展：滑动窗口中至多k个0，用队列保存各0的下标。
        const int k = 1;
        int ans = 0;
        queue<int> zeroIdx;
        for (int lo = 0, hi = 0; hi < nums.size(); hi++) {
            if (nums[hi] == 0) zeroIdx.push(hi);
            
            while (zeroIdx.size() > k) {
                lo = zeroIdx.front() + 1;
                zeroIdx.pop();
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
