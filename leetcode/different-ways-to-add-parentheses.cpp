//
//  different-ways-to-add-parentheses
//  https://leetcode.com/problems/different-ways-to-add-parentheses/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') { // 分治
                auto ans1 = diffWaysToCompute(input.substr(0, i));
                auto ans2 = diffWaysToCompute(input.substr(i + 1));
                for (auto n1 : ans1) {
                    for (auto n2 : ans2) {
                        if (c == '+') {
                            ans.push_back(n1 + n2);
                        } else if (c == '-') {
                            ans.push_back(n1 - n2);
                        } else {
                            ans.push_back(n1 * n2);
                        }
                    }
                }
            }
        }
        if (ans.empty()) { // input是纯数字串
            ans.push_back(stoi(input));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto ans = solution.diffWaysToCompute("2*3-4*5");
    for (auto num : ans) {
        cout << num << " ";
    }
    
    return 0;
}
