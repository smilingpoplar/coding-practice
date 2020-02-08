//
//  count-number-of-nice-subarrays
//  https://leetcode.com/problems/count-number-of-nice-subarrays/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        return atMost(nums, k) - atMost(nums, k-1);        
    }
    
    int atMost(vector<int> &nums, int k) {
        const int N = nums.size();        
        int ans = 0, oddCnt = 0;
        for (int lo = 0, hi = 0; hi < N; hi++) {
            if (nums[hi] % 2 == 1) oddCnt++;
            while (oddCnt > k) {
                if (nums[lo] % 2 == 1) oddCnt--;
                lo++;
            }
            ans += hi - lo + 1;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
