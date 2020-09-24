//
//  smallest-range
//  https://leetcode.com/problems/smallest-range/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int N = nums.size();
        vector<int> idx(N, 0); // idx[]存各数组的当前下标，数组i的当前元素是nums[i][idx[i]]
        auto cmp = [&](int i, int j) { // 最小堆
            return nums[i][idx[i]] > nums[j][idx[j]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int rangeEnd = INT_MIN;
        for (int i = 0; i < N; i++) {
            if (nums[i].empty()) break;
            pq.push(i);
            rangeEnd = max(rangeEnd, nums[i][0]);
        }
        if (pq.size() < N) return { INT_MIN, INT_MAX };

        vector<int> ans;
        int minRangeSize = INT_MAX;
        while (true) {
            int minQ = pq.top(); pq.pop();
            int rangeBegin = nums[minQ][idx[minQ]];
            int rangeSize = rangeEnd - rangeBegin + 1;
            if (rangeSize < minRangeSize) {
                minRangeSize = rangeSize;
                ans = { rangeBegin, rangeEnd };
            }
            // 移动指针，下一元素
            idx[minQ]++;
            if (idx[minQ] == nums[minQ].size()) break;
            pq.push(minQ);
            rangeEnd = max(rangeEnd, nums[minQ][idx[minQ]]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
