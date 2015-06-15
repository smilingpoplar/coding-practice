//
//  anagrams
//  https://leetcode.com/problems/anagrams/
//
//  Created by smilingpoplar on 15/6/15.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const auto &str : strs) {
            string s(str);
            sort(s.begin(), s.end());
            map[s].push_back(str);
        }
        
        vector<string> result;
        for (const auto &kv : map) {
            const auto &v = kv.second;
            if (v.size() > 1) {
                for (auto it = v.begin(); it != v.end(); ++it) {
                    result.push_back(*it);
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> strs = {"aba", "abc", "baa"};
    Solution solution;
    auto result = solution.anagrams(strs);
    for (const auto &s : result) {
        cout << s << " ";
    }
    
    return 0;
}
