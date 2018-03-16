//
//  degree-of-an-array
//  https://leetcode.com/problems/degree-of-an-array/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // 每个数都记录出现次数、最左出现位置、最右出现位置
        unordered_map<int, int> count;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            ++count[x];
            if (!left.count(x)) left[x] = i;
            right[x] = i;
        }
        
        int degree = INT_MIN;
        for (const auto &e : count) {
            degree = max(degree, e.second);
        }
        
        int ans = INT_MAX;
        for (const auto &e : count) {
            if (e.second == degree) {
                int x = e.first;
                ans = min(ans, right[x] - left[x] + 1);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
