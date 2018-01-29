//
//  is-subsequence
//  https://leetcode.com/problems/is-subsequence/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < t.size() && i < s.size(); j++) {
            if (s[i] == t[j]) i++;
        }
        return i == s.size();
    }
};
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // follow up，预处理t
        vector<vector<int>> pos(26);
        for (int i = 0; i < t.size(); i++) {
            pos[t[i] - 'a'].push_back(i);
        }
        
        int idx = -1;
        for (char c : s) {
            auto &list = pos[c - 'a'];
            auto it = upper_bound(list.begin(), list.end(), idx);
            if (it == list.end()) return false;
            idx = *it;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
