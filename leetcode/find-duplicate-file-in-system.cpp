//
//  find-duplicate-file-in-system
//  https://leetcode.com/problems/find-duplicate-file-in-system/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for (auto &path : paths) {
            parse(path, mp);
        }
        vector<vector<string>> ans;
        for (auto &e : mp) {
            auto &paths = e.second;
            if (paths.size() > 1) ans.push_back(paths);
        }
        return ans;
    }
    
    void parse(const string &path, unordered_map<string, vector<string>> &mp) {
        istringstream iss(path);
        string str;
        vector<string> strs;
        while (iss >> str) {
            strs.push_back(str);
        }
        
        for (int i = 1; i < strs.size(); i++) {
            auto pos = strs[i].find('(');
            auto file = strs[i].substr(0, pos);
            auto content = strs[i].substr(pos + 1, strs[i].size() - pos - 2);
            mp[content].push_back(strs[0] + "/" + file);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
