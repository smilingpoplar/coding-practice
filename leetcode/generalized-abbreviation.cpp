//
//  generalized-abbreviation
//  https://leetcode.com/problems/generalized-abbreviation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        dfs(word, 0, 0, "", ans);
        return ans;
    }
    
    void dfs(const string &word, int idx, int count, string abbr, vector<string> &ans) {
        if (idx == word.size()) {
            if (count > 0) abbr += to_string(count);
            ans.push_back(abbr);
            return;
        }
        // 对每个字母，或者：省略它、并增加计数
        dfs(word, idx + 1, count + 1, abbr, ans);
        // 或者：计数>0时输出累加的数字、再输出字母
        abbr += (count > 0 ? to_string(count) : "") + word[idx];
        dfs(word, idx + 1, 0, abbr, ans);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
