//
//  contiguous-array
//  https://leetcode.com/problems/contiguous-array/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp; // sum=>pos
        int runningSum = 0; // 初始空集和
        mp[runningSum] = -1;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i] == 0 ? -1 : 1;
            if (!mp.count(runningSum)) {
                mp[runningSum] = i;
            } else {
                ans = max(ans, i - mp[runningSum]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
