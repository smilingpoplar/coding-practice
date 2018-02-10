//
//  pascals-triangle
//  https://leetcode.com/problems/pascals-triangle/
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
        search(num, target, 0, 0, 0, "", ans);
        return ans;
    }
    
    void search(string num, int target, int idx,
                long prevExprEval, long prevValue,
                string expr, vector<string> &ans) {
        if (idx == num.size()) {
            if (prevExprEval == target)
                ans.push_back(expr);
            return;
        }
        
        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') continue; // 多位数却以"0"开头
            auto curr = num.substr(idx, i - idx + 1);
            long currValue = stol(curr);
            if (idx == 0) {
                search(num, target, i + 1, currValue, currValue, curr, ans);
            } else {
                search(num, target, i + 1, prevExprEval + currValue, currValue, expr + "+" + curr, ans);
                search(num, target, i + 1, prevExprEval - currValue, -currValue, expr + "-" + curr, ans);
                // 比如 prevExprEval=1+2+3，现在遇到*4，要prevExprEval-3+3*4
                search(num, target, i + 1, prevExprEval - prevValue + prevValue * currValue,
                       prevValue * currValue, expr + "*" + curr, ans);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
