//
//  remove-duplicate-letters
//  https://leetcode.com/problems/remove-duplicate-letters/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 要使剩余串的字典序最小，需要留下递增栈，找下一个更小的数
        // 已入选栈中不再考虑；某字母有剩余时才可pop()
        vector<int> cnt(128, 0); // 各字母有多少富余
        for (char c : s) cnt[c]++;
        vector<bool> picked(128, false);

        string stk;
        for (char c : s) {
            cnt[c]--;
            if (picked[c]) continue;
            while (!stk.empty() && c < stk.back() 
                    && cnt[stk.back()] > 0) {
                int top = stk.back(); stk.pop_back();
                picked[top] = false;
            }
            stk.push_back(c);
            picked[c] = true;
        }
        return stk;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
