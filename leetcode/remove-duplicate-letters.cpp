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
        vector<int> count(128);
        for (char c : s) count[c]++;
        
        vector<bool> visited(128);
        string stk; // 让栈中保留递增序列，对应"波峰"左侧，对应找下一个更小的数
        for (char c : s) {
            count[c]--;
            if (visited[c]) continue; // 保证每个字母最多选一次
            // count[stk.back()]>0时才弹出，说明字母有富余时才弹出，保证每个字母最少选一次
            while (!stk.empty() && c < stk.back() && count[stk.back()] > 0) {
                int pop = stk.back();
                stk.pop_back();
                visited[pop] = false;
            }
            stk.push_back(c);
            visited[c] = true;
        }
        return stk;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
