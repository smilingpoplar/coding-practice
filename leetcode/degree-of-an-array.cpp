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
        unordered_map<int, int> cnt;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            cnt[x]++;
            if (!left.count(x)) left[x] = i;
            right[x] = i;
        }
        
        int degree = INT_MIN;
        for (auto &e : cnt) {
            degree = max(degree, e.second);
        }
        
        int ans = INT_MAX;
        for (auto &e : cnt) {
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
