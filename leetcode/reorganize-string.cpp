//
//  reorganize-string
//  https://leetcode.com/problems/reorganize-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        // https://leetcode.com/problems/rearrange-string-k-distance-apart/ 的特例
        // 可行需 最多的字符数 <= 由其他所有字符隔开的空槽
        // 即 maxCnt <= N-maxCnt+1，2*maxCnt <= N+1
        const int N = S.size();
        int maxCnt = INT_MIN;
        unordered_map<char, int> cnt;
        for (char c : S) {
            cnt[c]++;
            maxCnt = max(maxCnt, cnt[c]);
        }
        if (2 * maxCnt > N + 1) return "";  // 此判断之后一定可行

        auto cmp = [&cnt](char a, char b) { return cnt[a] < cnt[b]; };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
        for (auto &e : cnt) pq.push(e.first);

        string ans;
        queue<char> freezed;
        while (!pq.empty()) {
            char c = pq.top();
            pq.pop();
            ans += c;
            cnt[c]--;

            freezed.push(c);
            if (freezed.size() >= 2) {  // 相同字母至少距离2
                int released = freezed.front();
                freezed.pop();
                if (cnt[released] > 0) pq.push(released);
            }
        }
        return ans;
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
