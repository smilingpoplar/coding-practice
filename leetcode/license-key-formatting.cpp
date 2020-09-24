//
//  license-key-formatting
//  https://leetcode.com/problems/license-key-formatting/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        // 从后往前，数到第K+1个字符时先输出个'-'
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == '-') continue;
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
