//
//  longest-uncommon-subsequence-ii
//  https://leetcode.com/problems/longest-uncommon-subsequence-ii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> count;
        for (string & s : strs)
            count[s]++;
        
        sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
            return a.size() > b.size();
        });
        for (int i = 0; i < strs.size(); i++) {
            if (count[strs[i]] > 1) continue;
            int j = 0;
            while (j < i && !isSubsequence(strs[i], strs[j]))
                j++;
            if (j == i) return strs[i].size();
        }
        return -1;
    }
    
    bool isSubsequence(const string &sub, const string &str) {
        int idx = 0;
        for (char c : str) {
            if (idx < sub.size() && sub[idx] == c) idx++;
        }
        return idx == sub.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
