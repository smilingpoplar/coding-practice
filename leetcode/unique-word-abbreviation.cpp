//
//  unique-word-abbreviation
//  https://leetcode.com/problems/unique-word-abbreviation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class ValidWordAbbr {
    unordered_map<string, set<string>> mp; // abbr=>words
public:
    ValidWordAbbr(vector<string> dictionary) {
        // 按abbr分桶
        for (auto &word : dictionary) {
            auto abbr = toAbbr(word);
            mp[abbr].insert(word);
        }
    }
    
    bool isUnique(string word) {
        auto abbr = toAbbr(word);
        return (!mp.count(abbr) || (mp[abbr].size() == 1 && mp[abbr].count(word)));
    }
    
    string toAbbr(const string &word) {
        const int N = word.size();
        if (N <= 2) return word;
        return word[0] + to_string(N - 2) + word[N-1];
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
