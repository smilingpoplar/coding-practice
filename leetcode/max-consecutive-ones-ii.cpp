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
        const int N = nums.size();
        int zeroCnt = 0, ans = INT_MIN;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            if (nums[hi] == 0) zeroCnt++;
            while (zeroCnt > 1) {
                if (nums[lo++] == 0) zeroCnt--;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
