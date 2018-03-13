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
        // 贪婪法，优先选择剩余最多的字母；再用个freezed队列存放暂不能输出的字母
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        auto cmp = [](const Pair &a, const Pair &b) {
            return a.second < b.second;
        };
        priority_queue<Pair, vector<Pair>, decltype(cmp)> pq(cmp);
        for (auto &e : count) pq.push(e);
        
        string ans;
        queue<Pair> freezed;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ans += top.first;
            // 字母输出后放入freezed队列
            top.second--;
            freezed.push(top);
            if (freezed.size() >= k) {
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
