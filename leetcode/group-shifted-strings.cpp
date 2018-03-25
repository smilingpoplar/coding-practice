//
//  group-shifted-strings
//  https://leetcode.com/problems/group-shifted-strings/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // 同组单词：字符间的增量序列相同，所以把增量序列编码
        // 由["az","ba"]，25（z-a增量）== -1（a-b增量），即负增量要加26变成正增量
        unordered_map<string, vector<string>> mp; // 增量序列的编码=>strs
        for (auto &str : strings)
            mp[encode(str)].push_back(str);

        vector<vector<string>> ans;
        for (auto &e : mp)
            ans.push_back(e.second);
        return ans;
    }
    
    string encode(const string &str) {
        string ans;
        for (int i = 1; i < str.size(); i++) {
            int delta = str[i] - str[i-1];
            if (delta < 0) delta += 26;
            ans += 'a' + delta; // 增量转成字母来编码
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
