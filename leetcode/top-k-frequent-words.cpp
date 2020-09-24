//
//  top-k-frequent-words
//  https://leetcode.com/problems/top-k-frequent-words/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto &w : words) cnt[w]++;
       
        // 留下cnt大、字母序小的
        auto cmp = [&cnt](const string &a, const string &b) {
            if (cnt[a] == cnt[b]) return a < b;
            return cnt[a] > cnt[b];
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for (auto &e : cnt) {
            pq.push(e.first);
            if (pq.size() > k) pq.pop();
        }
        
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
