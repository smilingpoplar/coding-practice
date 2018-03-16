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
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        unordered_set<char> selected;
        vector<char> stk; // 让栈中保留递增序列
        for (char c : s) {
            count[c]--;
            // 当前字母已入栈，忽略掉，因为选新的并不能使结果更好
            if (selected.count(c)) continue;
            
            while (!stk.empty() && c < stk.back() && count[stk.back()] > 0) { // 栈顶可弹出
                int top = stk.back();
                stk.pop_back();
                selected.erase(top);
            }
            stk.push_back(c);
            selected.insert(c);
        }
        return string(stk.begin(), stk.end());
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
