//
//  count-of-range-sum
//  https://leetcode.com/problems/count-of-range-sum/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<long, int> mp; // sum=>count
        long runningSum = 0;
        mp[runningSum] = 1;
        
        int ans = 0;
        for (int num : nums) {
            runningSum += num;
            // 找数x使lower<= runningSum-x <=upper，runningSum-upper<= x <=runningSum-lower
            auto it1 = mp.lower_bound(runningSum - upper);
            auto it2 = mp.upper_bound(runningSum - lower);
            for (auto it = it1; it != it2; it++) {
                ans += it->second;
            }
            mp[runningSum]++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.generate(10);
    for (const auto &row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
