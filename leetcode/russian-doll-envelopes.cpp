//
//  russian-doll-envelopes
//  https://leetcode.com/problems/russian-doll-envelopes/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 长宽同时递增的最长子序列
        // 按width排序，然后根据height找最长递增子序列
        // width相等时按照height递减排序，能避免选中[3,4],[3,5]这种情况
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        // 根据height找LIS，O(nlgn)
        vector<int> tails;  // 各长度LIS的最小尾元素
        for (auto& e : envelopes) {
            int height = e[1];
            auto it = lower_bound(tails.begin(), tails.end(), height);
            if (it != tails.end()) {
                *it = height;
            } else {
                tails.push_back(height);
            }
        }
        return tails.size();
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
