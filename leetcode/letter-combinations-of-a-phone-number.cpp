//
//  letter-combinations-of-a-phone-number
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
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
        
        vector<string> ans;
        string comb;
        search(digits, 0, mapping, comb, ans);
        return ans;
    }
private:
    void search(const string &digits, int idx, const vector<string> &mapping,
                string &comb, vector<string> &ans) {
        if (idx == digits.size()) {
            ans.push_back(comb);
            return;
        }
        
        const string &letters = mapping[digits[idx] - '0'];
        for (char c : letters) {
            comb.push_back(c);
            search(digits, idx + 1, mapping, comb, ans);
            comb.pop_back();
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
