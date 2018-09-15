//
//  shifting-letters
//  https://leetcode.com/problems/shifting-letters/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        // 第i个字母总共shift：sum(shifts[i..])次
        const int N = S.size();
        int suffix = 0;
        for (int i = N - 1; i >= 0; i--) {
            shifts[i] = (shifts[i] + suffix) % 26;
            suffix = shifts[i];
        }

        string ans;
        for (int i = 0; i < N; i++) {
            ans += (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
