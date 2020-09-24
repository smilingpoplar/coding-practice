//
//  replace-the-substring-for-balanced-string
//  https://leetcode.com/problems/replace-the-substring-for-balanced-string/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int balancedString(string s) {
        const int N = s.size();
        unordered_map<char, int> cnt; // char=>count
        for (char c : s) {
            cnt[c]++;
        }
        unordered_map<char, int> excess;
        for (auto &e : cnt) {
            e.second -= N / 4;
            if (e.second > 0) excess[e.first] = e.second;
        }
        if (excess.empty()) return 0;
        // 找出包含所有富余字符的最小窗口
        int k = excess.size(), ans = INT_MAX;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            if (--cnt[s[hi]] == 0) k--;
            while (k == 0) { // 包含所有
                ans = min(ans, hi - lo + 1);
                if (cnt[s[lo]]++ == 0) k++;
                lo++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
