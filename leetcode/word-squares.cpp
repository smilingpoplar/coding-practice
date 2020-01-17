//
//  word-squares
//  https://leetcode.com/problems/word-squares/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        // b a l l
        // a r e a
        // l e a d
        // l a d y
        // 第0行选定后，第1行要以a开头（ball[1]）；
        // 第1行选定后，第2行要以le开头（ball[2]、area[2]）；
        // 第2行选定后，第3行要以lad开头（ball[3]、area[3]、lead[3]）；
        // ...        第k行要以串rows[0..k-1][k]开头
        // 需要根据前缀找单词的功能，可以用prefix=>wordIdx[]的哈希表，或者tire节点中存wordIdx[]
        if (words.empty()) return {};
        unordered_map<string, vector<int>> mp; // prefix=>wordIdx[]
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                auto prefix = words[i].substr(0, j + 1);
                mp[prefix].push_back(i);
            }
        }
        // 回溯法
        vector<vector<string>> ans;
        vector<string> rows;
        for (auto &word : words) {
            rows.push_back(word);
            search(rows, words, mp, ans);
            rows.pop_back();
        }
        return ans;
    }
    
    void search(vector<string> &rows, vector<string> &words,
                unordered_map<string, vector<int>> &mp, vector<vector<string>> &ans) {
        if (rows.size() == words[0].size()) { // 有len(word)行
            ans.push_back(rows);
            return;
        }
        
        int k = rows.size(); // 第k行要以rows[0..k-1][k]开头
        string prefix;
        for (int i = 0; i < k; i++) {
            prefix += rows[i][k];            
        }
        for (int idx : mp[prefix]) { // 前缀为prefix的那些单词，可作为rows[]新一行的候选
            rows.push_back(words[idx]);
            search(rows, words, mp, ans);
            rows.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
