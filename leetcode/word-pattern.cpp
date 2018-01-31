//
//  word-pattern
//  https://leetcode.com/problems/word-pattern/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        string word;
        istringstream iss(str);
        while (iss >> word) {
            words.push_back(word);
        }
        if (words.size() != pattern.size()) return false;
        
        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;
        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern[i];
            const string &w = words[i];
            bool patternMatched = p2w.find(p) != p2w.end();
            bool wordMatched = w2p.find(w) != w2p.end();
            if (!patternMatched && !wordMatched) {
                p2w[pattern[i]] = words[i];
                w2p[words[i]] = pattern[i];
            } else if ((patternMatched && p2w[p] != w)
                       || (wordMatched && w2p[w] != p)) {
                return false;
            }
        }
        return true;            
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
