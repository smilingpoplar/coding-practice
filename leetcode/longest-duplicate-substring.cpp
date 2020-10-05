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

/*
string longestDupSubstring(string S) {
    const int N = S.size();
    string_view sv(S);
    
    vector<string_view> arr; // suffix array
    for (int i = 0; i < N; i++) {
        arr.push_back(sv.substr(i));
    }
    sort(begin(arr), end(arr));
    
    string ans;
    int maxLen = 0;
    for (int i = N - 1; i > 0; i--) { // from N-1 to 1, case "aaaaa..."
        if (arr[i].size() < maxLen || arr[i-1].size() < maxLen) continue;
        
        int len = lenCommonPrefix(arr[i], arr[i-1]);
        if (len > maxLen) {
            maxLen = len;
            ans = arr[i].substr(0, len);
        }
    }
    return ans;
}

int lenCommonPrefix(string_view a, string_view b) {
    int len = 0;
    while (len < a.size() && len < b.size() 
            && a[len] == b[len]) {
        len++;
    }
    return len;
}
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
