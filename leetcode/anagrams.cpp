//
//  anagrams
//  https://leetcode.com/problems/anagrams/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (const auto &str : strs) {
            string key(str);
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto &kv : map) {
            auto &v = kv.second;
            sort(v.begin(), v.end());
            result.push_back(v);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    auto result = solution.groupAnagrams(strs);
    for (const auto &group : result) {
        for (const auto &s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
    
    return 0;
}
