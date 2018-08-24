//
//  reorganize-string
//  https://leetcode.com/problems/reorganize-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        // 是 https://leetcode.com/problems/rearrange-string-k-distance-apart/ 的特例
        // 可行只需 最多的字符个数 <= 其他所有字符隔开的空槽 = 其他所有字符个数和+1
        // 即 maxCnt <= N-maxCnt+1，maxCnt <= (N+1)/2
        unordered_map<int, int> cnt;
        for (char c : S) cnt[c]++;
        auto cmp = [&cnt](char a, char b) { return cnt[a] < cnt[b]; };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
        int maxCnt = INT_MIN, maxCntLimit = (S.size() + 1) / 2;
        for (auto &e : cnt) {
            maxCnt = max(maxCnt, e.second);
            if (maxCnt > maxCntLimit) return "";
            pq.push(e.first);
        }

        // 每次输出剩余最多的两个字符
        ostringstream oss;
        while (pq.size() >= 2) {
            char a = pq.top(); pq.pop();
            char b = pq.top(); pq.pop();
            oss << a << b;
            if (--cnt[a] > 0) pq.push(a);
            if (--cnt[b] > 0) pq.push(b);
        }
        if (!pq.empty()) {
            oss << pq.top();
            pq.pop();
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
