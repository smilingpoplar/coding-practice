//
//  find-and-replace-pattern
//  https://leetcode.com/problems/find-and-replace-pattern/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto &word : words) {
            if (isMatch(word, pattern)) 
                ans.push_back(word);
        }
        return ans;
    }
    
    bool isMatch(const string &word, const string &pattern) {
        if (word.size() != pattern.size()) return false;
        const int N = word.size();
        // 把一一对应的pattern中字母和word中的字母同时映射到[1..N]
        unordered_map<char, int> w2i, p2i;
        for (int i = 0; i < N; i++) {
            char w = word[i], p = pattern[i];
            if (p2i[p] != w2i[w]) return false;
            p2i[p] = w2i[w] = i + 1;
        }
        return true;        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
