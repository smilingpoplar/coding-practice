//
//  rearrange-string-k-distance-apart
//  https://leetcode.com/problems/rearrange-string-k-distance-apart/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using Pair = pair<char, int>;
    string rearrangeString(string s, int k) {
        if (k == 0) return s; // 两字母相隔1>=0，不用重排
        
        // 贪婪法，优先选择剩余最多的字母
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        // 优先队列比较完count再比较char，作为键值的char不可能相同，所以队列项不可能相同，排序稳定
        auto cmp = [](const Pair &a, const Pair &b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue<Pair, vector<Pair>, decltype(cmp)> pq(cmp);
        for (auto &e : count) pq.push(e);
        
        string ans;
        while (!pq.empty()) {
            vector<Pair> cache;
            // 一批次处理k个，且优先队列排序稳定
            for (int i = 0; i < k; i++) {
                if (pq.empty()) return "";
                auto top = pq.top(); pq.pop();
                ans += top.first;
                if (ans.size() == s.size()) return ans;
                if (--top.second > 0) cache.push_back(top);
            }
            for (auto &e : cache) pq.push(e);
        }
        return "";
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
