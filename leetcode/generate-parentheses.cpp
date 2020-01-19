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

    void search(int leftRemain, int rightRemain, string paren, vector<string> &ans) {
        // 确保 0 <= leftRemain <= rightRemain
        if (leftRemain == 0 && rightRemain == 0) {
            ans.push_back(paren);
            return;
        }
        
        if (leftRemain > 0) search(leftRemain - 1, rightRemain, paren + '(', ans);
        if (leftRemain < rightRemain) search(leftRemain, rightRemain - 1, paren + ")", ans);
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
