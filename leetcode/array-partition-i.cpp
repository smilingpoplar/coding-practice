//
//  array-partition-i
//  https://leetcode.com/problems/array-partition-i/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
