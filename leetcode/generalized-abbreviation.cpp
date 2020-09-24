//
//  generalized-abbreviation
//  https://leetcode.com/problems/generalized-abbreviation/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        search(word, 0, 0, "", ans);
        return ans;
    }
    
    // count表示在word[idx..]之前有几个被省略还未输出
    void search(const string &word, int idx, int count, string abbr, vector<string> &ans) {
        if (idx == word.size()) {
            if (count > 0) abbr += to_string(count);
            ans.push_back(abbr);
            return;
        }
        // 对每个字母，或者：省略它、并增加计数
        search(word, idx + 1, count + 1, abbr, ans);
        // 或者：计数>0时输出计数、再输出字母
        abbr += (count > 0 ? to_string(count) : "") + word[idx];
        search(word, idx + 1, 0, abbr, ans);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
