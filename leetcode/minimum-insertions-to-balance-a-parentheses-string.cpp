//
//  minimum-insertions-to-balance-a-parentheses-string
//  https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        const int N = s.size();
        int ans = 0;
        stack<char> stk;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
            } else { // ')'
                if (stk.empty()) {
                    ans++;
                    stk.push('(');
                }
                if (i + 1 < N && s[i+1] == ')') {
                    i++;
                    stk.pop();
                } else {
                    ans++;
                    stk.pop();
                }
            }
        }
        ans += stk.size() * 2;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
