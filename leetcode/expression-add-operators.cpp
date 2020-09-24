//
//  expression-add-operators
//  https://leetcode.com/problems/expression-add-operators/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    
    void search(string num, int target, int idx, string lastExprStr, 
                long lastExprVal, long lastNum, vector<string> &ans) {
        if (idx == num.size()) {
            if (lastExprVal == target) ans.push_back(lastExprStr);
            return;
        }

        // [idx..i]是currStr, [i+1..]进递归
        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') continue; // 多位数不能以"0"开头
            auto currStr = num.substr(idx, i - idx + 1);
            long currNum = stol(currStr);
            if (idx == 0) {
                search(num, target, i + 1, currStr, currNum, currNum, ans);
            } else {
                search(num, target, i + 1, lastExprStr + "+" + currStr, 
                       lastExprVal + currNum, currNum, ans);
                search(num, target, i + 1, lastExprStr + "-" + currStr, 
                       lastExprVal - currNum, -currNum, ans);
                // 比如 lastExprVal=1+2+3，现在遇到*4，要lastExprVal-3+3*4
                // 若再遇到*5，要lastExprVal-(3*4)+(3*4)*5
                search(num, target, i + 1, lastExprStr + "*" + currStr, 
                       lastExprVal - lastNum + lastNum * currNum, lastNum * currNum, ans);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
