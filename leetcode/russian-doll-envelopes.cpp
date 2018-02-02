//
//  russian-doll-envelopes
//  https://leetcode.com/problems/russian-doll-envelopes/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // 设dp[i]表示envelopes[0..i]的最长递增序列长
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        int ans = 0;
        for (int i = 0; i < envelopes.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i].first > envelopes[j].first &&
                   envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
*/

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // 按width排序，width相等时按照height递减排序。
        // 这样后面只看height找递增，也能避免选中width相等的不该选情况。
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        // O(nlgn)根据height找LIS
        vector<int> tails; // 各长度LIS的最小尾元素
        for (auto &e : envelopes) {
            int height = e.second;
            auto it = lower_bound(tails.begin(), tails.end(), height);
            if (it == tails.end()) {
                tails.push_back(height);
            } else {
                *it = height;
            }
        }
        return tails.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
