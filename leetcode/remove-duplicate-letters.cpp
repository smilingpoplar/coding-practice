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
        // 要使剩余串的字典序最小，需要栈中留下递增序列 <=> 找下一个更小的数
        // 限制条件：每个字母出现且仅出现一次
        vector<int> leftCnt(128, 0); // 某字母还有多少富余
        for (char c : s) leftCnt[c]++;
        vector<bool> appeared(128, false); // 某字母是否已出现

        string stk;
        for (char c : s) {
            leftCnt[c]--;
            if (appeared[c]) continue; // 最多出现一次，在开始就判断保证重复字母选左边的
            while (!stk.empty() && c < stk.back() 
                    && leftCnt[stk.back()] > 0) { // 有富余才能弹出，保证最少出现一次
                int top = stk.back(); stk.pop_back();
                appeared[top] = false;
            }
            stk.push_back(c);
            appeared[c] = true;
        }
        return stk;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
