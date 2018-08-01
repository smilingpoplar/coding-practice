//
//  expression-add-operators
//  https://leetcode.com/problems/expression-add-operators/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        search(num, target, 0, "", 0, 0, ans);
        return ans;
    }
    
    void search(string num, int target, int idx, string exprStr, 
                long exprEval, long prevNum, vector<string> &ans) {
        if (idx == num.size()) {
            if (exprEval == target) ans.push_back(exprStr);
            return;
        }

        // [0,idx)是exprStr, [idx,i]是currStr, [i+1,..]进递归
        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') continue; // 多位数、却以"0"开头
            auto currStr = num.substr(idx, i - idx + 1);
            long currNum = stol(currStr);
            if (idx == 0) {
                search(num, target, i + 1, currStr, currNum, currNum, ans);
            } else {
                search(num, target, i + 1, exprStr + "+" + currStr, 
                       exprEval + currNum, currNum, ans);
                search(num, target, i + 1, exprStr + "-" + currStr, 
                       exprEval - currNum, -currNum, ans);
                // 比如 exprEval=1+2+3，现在遇到*4，要exprEval-3+3*4
                search(num, target, i + 1, exprStr + "*" + currStr, 
                       exprEval - prevNum + prevNum * currNum, prevNum * currNum, ans);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
