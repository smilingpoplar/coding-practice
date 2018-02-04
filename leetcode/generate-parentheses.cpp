//
//  generate-parentheses
//  https://leetcode.com/problems/generate-parentheses/
//
//  Created by smilingpoplar on 15/6/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        search(n, n, "", ans);
        return ans;
    }
    
    void search(int lefts, int rights, string paren, vector<string> &ans) {
        // 0 <= 左括号剩余lefts <= 右括号剩余rights
        if (lefts == 0 && rights == 0) {
            ans.push_back(paren);
            return;
        }
        
        if (lefts > 0) search(lefts - 1, rights, paren+'(', ans);
        if (lefts < rights) search(lefts, rights - 1, paren + ")", ans);
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.generateParenthesis(3);
    for (const auto &parenthesis : result) {
        cout << parenthesis << endl;
    }
    
    return 0;
}
