//
//  longest-word-in-dictionary-through-deleting
//  https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
//
//  Created by smilingpoplar on 17/11/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string &a, const string &b) {
            return (a.size() > b.size()) || (a.size() == b.size() && a < b);
        });
        
        for (const string &word : d) {
            if (isSubsequence(s, word)) return word;
        }
        return "";
    }
    
    bool isSubsequence(const string &str, const string &sub) {
        int j = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == sub[j]) j++;
            if (j == sub.size()) return true;
        }
        return false;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
