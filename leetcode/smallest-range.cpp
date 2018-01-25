//
//  smallest-range
//  https://leetcode.com/problems/smallest-range/
//
//  Created by smilingpoplar on 17/12/07.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int N = nums.size();
        vector<int> cur(N, 0); // cur[]存各数组的当前下标，数组i的当前元素是nums[i][cur[i]]
        auto cmp = [&](int i, int j) { // 优先队列保存数组编号，最小堆，用>
            return nums[i][cur[i]] > nums[j][cur[j]];
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
            int minQ = pq.top();
            pq.pop();
            int rangeBegin = nums[minQ][cur[minQ]];
            int rangeSize = rangeEnd - rangeBegin + 1;
            if (rangeSize < minRangeSize) {
                minRangeSize = rangeSize;
                ans = { rangeBegin, rangeEnd };
            }
            // 移动指针，下一元素
            cur[minQ]++;
            if (cur[minQ] == nums[minQ].size()) break;
            pq.push(minQ);
            rangeEnd = max(rangeEnd, nums[minQ][cur[minQ]]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
