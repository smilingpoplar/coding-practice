//
//  letter-case-permutation
//  https://leetcode.com/problems/letter-case-permutation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        search(S, 0, ans);
        return ans;
    }
    
    void search(string &s, int pos, vector<string> &ans) {
        if (pos == s.size()) {
            ans.push_back(s);
            return;
        }
        
        search(s, pos + 1, ans);
        if (isalpha(s[pos])) {
            s[pos] ^= (1 << 5); // toggle case
            search(s, pos + 1, ans);
            s[pos] ^= (1 << 5); // toggle case
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
