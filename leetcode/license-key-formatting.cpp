//
//  license-key-formatting
//  https://leetcode.com/problems/license-key-formatting/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == '-') continue;
            // 算上'-'，K+1个一组
            if (ans.size() % (K+1) == K) ans.push_back('-');
            ans.push_back(toupper(S[i]));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
