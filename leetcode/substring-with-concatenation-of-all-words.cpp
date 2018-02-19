//
//  substring-with-concatenation-of-all-words
//  https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//
//  Created by smilingpoplar on 15/5/8.
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
        // s有M个起分点，构成M个序列，看每个序列有哪些子段满足条件
        for (int m = 0; m < M; m++) {
            // 滑动窗口，先移动end使窗口有效，再移动start使窗口最小
            auto theCount = count;
            auto theDistinct = distinct;
            int start = m, end = m;
            while (end + M <= s.size()) {
                auto endWord = s.substr(end, M);
                if (theCount.find(endWord) != theCount.end() 
                    && --theCount[endWord] == 0) theDistinct--;
                end += M;
                while (theDistinct == 0) { // 窗口有效
                    if (end - start == K * M) {
                        ans.push_back(start);
                    }
                    auto startWord = s.substr(start, M);
                    if (theCount.find(startWord) != theCount.end() 
                        && ++theCount[startWord] == 1) theDistinct++;
                    start += M;
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
