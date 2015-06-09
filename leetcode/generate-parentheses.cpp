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
        vector<string> result;
        string parenthesis;
        dfs(0, 0, n, parenthesis, result);
        return result;
    }
private:
    void dfs(int leftCount, int rightCount, const int n,
             string &parenthesis, vector<string> &result) {
        if (leftCount == n && rightCount == n) {
            result.push_back(parenthesis);
            return;
        }
        if (leftCount < n) {
            parenthesis.push_back('(');
            dfs(leftCount + 1, rightCount, n, parenthesis, result);
            parenthesis.pop_back();
        }
        if (rightCount < leftCount) {
            parenthesis.push_back(')');
            dfs(leftCount, rightCount + 1, n, parenthesis, result);
            parenthesis.pop_back();
        }
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
