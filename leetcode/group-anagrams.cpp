//
//  group-anagrams
//  https://leetcode.com/problems/group-anagrams/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto &s : strs) {
            string key(s);
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto &e : mp) {
            ans.push_back(e.second);
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {    
    return 0;
}
