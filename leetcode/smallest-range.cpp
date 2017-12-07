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
        vector<int> index(N, 0); // index[i]存数组nums[i]的当前下标
        auto cmp = [&](int i, int j) { // 用>, 最小堆，优先队列保存数组编号
            return nums[i][index[i]] > nums[j][index[j]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int rangeEnd = -1;
        for (int i = 0; i < N; i++) {
            if (nums[i].empty()) break;
            pq.push(i);
            rangeEnd = max(rangeEnd, nums[i][0]);
        }
        vector<int> ans({ INT_MIN, INT_MAX });
        if (pq.size() < N) return ans;

        int minRange = INT_MAX;
        while (true) {
            int minQ = pq.top();
            pq.pop();
            int rangeBegin = nums[minQ][index[minQ]];
            if (rangeEnd - rangeBegin < minRange) {
                minRange = rangeEnd - rangeBegin;
                ans = { rangeBegin, rangeEnd };
            }
            // 移动指针，下一元素
            index[minQ]++;
            if (index[minQ] == nums[minQ].size()) break;
            pq.push(minQ);
            rangeEnd = max(rangeEnd, nums[minQ][index[minQ]]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
