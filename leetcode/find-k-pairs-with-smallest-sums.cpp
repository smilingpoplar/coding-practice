//
//  find-k-pairs-with-smallest-sums
//  https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        // 用最小堆保存两数组索引
        auto cmp = [&](pair<int, int> &p1, pair<int, int> &p2) {
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        const int M = nums1.size();
        const int N = nums2.size();
        for (int i = 0; i < M; i++) {
            pq.push({ i, 0 });
        }

        vector<pair<int, int>> ans;
        while (!pq.empty() && k--) {
            auto p = pq.top(); pq.pop();
            ans.push_back({ nums1[p.first], nums2[p.second] });
            if (p.second + 1 < N) pq.push({ p.first, p.second + 1 });
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}