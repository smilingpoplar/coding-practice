//
//  count-of-range-sum
//  https://leetcode.com/problems/count-of-range-sum/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<long, int> cnt; // sum=>count
        long runningSum = 0;
        cnt[runningSum] = 1;
        
        int ans = 0;
        for (int num : nums) {
            runningSum += num;
            // 找数x使lower<= runningSum-x <=upper，runningSum-upper<= x <=runningSum-lower
            auto it1 = cnt.lower_bound(runningSum - upper);
            auto it2 = cnt.upper_bound(runningSum - lower);
            for (auto it = it1; it != it2; it++) {
                ans += it->second;
            }
            cnt[runningSum]++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
