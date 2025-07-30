//
//  find-all-anagrams-in-a-string
//  https://leetcode.com/problems/find-all-anagrams-in-a-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cnt;
        for (char c : p) cnt[c]++;
        int distinct = cnt.size();

        vector<int> ans;
        for (int hi = 0, lo = 0; hi < s.size(); hi++) {
            if (--cnt[s[hi]] == 0) distinct--;
            while (distinct == 0) {  // 包含p的异形词
                if (hi - lo + 1 == p.size()) ans.push_back(lo);
                if (cnt[s[lo]]++ == 0) distinct++;
                lo++;
            }
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
