//
//  word-abbreviation
//  https://leetcode.com/problems/word-abbreviation/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        // 先按最短前缀生成abbr，有冲突再把前缀变长
        vector<string> abbrs;
        vector<int> prefixSizes;
        for (auto &word : dict) {
            abbrs.push_back(getAbbr(word, 1));
            prefixSizes.push_back(1);
        }
        
        const int N = dict.size();
        for (int i = 0; i < N - 1; i++) {
            // 看abbrs[i]跟后面哪些有冲突
            while (true) {
                set<int> dup;
                for (int j = i + 1; j < N; j++) {
                    if (abbrs[j] == abbrs[i]) dup.insert(j);
                }
                if (dup.empty()) break;
                // 有冲突，把前缀变长
                dup.insert(i);
                for (int d : dup) {
                    abbrs[d] = getAbbr(dict[d], ++prefixSizes[d]);
                }
            }
        }
        return abbrs;
    }
    
    string getAbbr(const string &word, int prefixSize) {
        const int N = word.size();
        int abbrLen = N - prefixSize - 1;
        if (abbrLen <= 1) return word;
        return word.substr(0, prefixSize) + to_string(abbrLen) + word[N-1];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
