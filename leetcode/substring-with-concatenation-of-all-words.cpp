//
//  substring-with-concatenation-of-all-words
//  https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        const int K = words.size(), M = words[0].size();
        unordered_map<string, int> count;
        for (auto &w : words) count[w]++;
        int distinct = count.size();
        
        vector<int> ans;
        // s有M个起分点，构成M个序列，看各个序列有哪些子段满足条件
        for (int m = 0; m < M; m++) {
            // 滑动窗口，每次hi移动一步：若是有效窗口、lo再移动至无效窗口
            auto theCount = count;
            int theDistinct = distinct;
            for (int lo = m, hi = m; hi + M <= s.size(); hi += M) {
                auto hiWord = s.substr(hi, M);
                if (--theCount[hiWord] == 0) theDistinct--;
                while (theDistinct == 0) { // 有效窗口
                    if (hi + M - lo == K * M) {
                        ans.push_back(lo);
                    }
                    auto loWord = s.substr(lo, M);
                    if (theCount[loWord]++ == 0) theDistinct++;
                    lo += M;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<string> words = {"a","b","a"};
    auto result = solution.findSubstring("abababab", words);
    for (int index : result) {
        cout << index << " ";
    }
    
    return 0;
}
