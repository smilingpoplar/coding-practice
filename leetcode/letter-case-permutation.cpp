//
//  letter-case-permutation
//  https://leetcode.com/problems/letter-case-permutation/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    
    void search(string &s, int idx, vector<string> &ans) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }
        
        search(s, idx + 1, ans);
        if (isalpha(s[idx])) {
            // 根据ascii表，letter^=32就变换大小写
            // 32 == 刚好>字母数26的 2的幂
            s[idx] ^= 32;
            search(s, idx + 1, ans);
            s[idx] ^= 32;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
