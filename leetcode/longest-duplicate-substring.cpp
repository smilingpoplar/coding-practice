//
//  longest-duplicate-substring
//  https://leetcode.com/problems/longest-duplicate-substring/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string longestDupSubstring(string S) {
        // 猜重复串的长度l，test(l)表示不存在长为l的重复串，
        // 随着l增长，会返回[0..0 1..1]形式，符合二分法要求
        // 下面用findDupIdx返回重复串的起始下标，不存在重复串则返回-1
        const int N = S.size();
        int loIdx = -1;
        int l = 0, u = N;
        while (l + 1 < u) {
            int m = l + (u - l) / 2;
            int dupIdx = findDupIdx(m, S);
            if (dupIdx < 0) {
                u = m;
            } else {
                loIdx = dupIdx;
                l = m;
            }
        }
        if (loIdx < 0) return "";
        return S.substr(loIdx, l);
    }

    int findDupIdx(int len, const string &s) {
        const int N = s.size();
        unordered_set<string_view> seen;
        for (int i = 0; i + len <= N; i++) {
            auto [_, succ] = seen.emplace(s.data() + i, len);
            if (!succ) return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
