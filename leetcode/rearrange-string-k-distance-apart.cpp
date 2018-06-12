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
        // 贪婪法，优先选择剩余最多的字母；每个字母输出后进入freezed队列，冻住>=k个字母时队头解冻
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        auto cmp = [](const Pair &a, const Pair &b) {
            return a.second < b.second; // 最大堆
        };
        priority_queue<Pair, vector<Pair>, decltype(cmp)> pq(cmp);
        for (auto &e : count) pq.push(e);
        
        string ans;
        queue<Pair> freezed;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ans += top.first;
            top.second--;
            // 每个字母输出后进入freezed队列，包括{c,0}
            freezed.push(top);
            if (freezed.size() >= k) { // 冻住>=k个字母时队头解冻
                auto release = freezed.front(); freezed.pop();
                if (release.second > 0) pq.push(release);
            }
        }
        return ans.size() == s.size() ? ans : "";
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
