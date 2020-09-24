//
//  diagonal-traverse-ii
//  https://leetcode.com/problems/diagonal-traverse-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // 每条对角线上rIdx+cIdx=某常数，可以把这个常数作为桶下标，
        // 这样就把一条对角线上的数都放到了一个桶里
        const int R = nums.size();
        vector<vector<int>> buckets;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < nums[r].size(); c++) {
                if (r + c >= buckets.size()) buckets.push_back({});
                buckets[r+c].push_back(nums[r][c]);
            }
        }
        // 每条对角线上的数是逆序放入桶中的
        vector<int> ans;
        for (auto &bucket : buckets) {
            for (auto it = bucket.rbegin(); it != bucket.rend(); it++) {
                ans.push_back(*it);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
