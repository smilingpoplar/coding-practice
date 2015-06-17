//
//  letter-combinations-of-a-phone-number
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        const vector<string> mapping = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> result;
        string combination;
        dfs(0, digits, mapping, combination, result);
        return result;
    }
private:
    void dfs(int index, const string &digits, const vector<string> &mapping,
             string &combination, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }
        
        const string &letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            combination.push_back(c);
            dfs(index + 1, digits, mapping, combination, result);
            combination.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.letterCombinations("");
    for (const auto &combination : result) {
        cout << combination << " ";
    }
 
    return 0;
}