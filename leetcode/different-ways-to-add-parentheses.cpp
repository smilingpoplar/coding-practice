//
//  different-ways-to-add-parentheses
//  https://leetcode.com/problems/different-ways-to-add-parentheses/
//
//  Created by smilingpoplar on 15/8/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') { // 分治
                auto result1 = diffWaysToCompute(input.substr(0, i));
                auto result2 = diffWaysToCompute(input.substr(i + 1));
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (c == '+') {
                            result.push_back(n1 + n2);
                        } else if (c == '-') {
                            result.push_back(n1 - n2);
                        } else {
                            result.push_back(n1 * n2);
                        }
                    }
                }
            }
        }
        if (result.empty()) { // input是纯数字串
            result.push_back(stoi(input));
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.diffWaysToCompute("2*3-4*5");
    for (auto num : result) {
        cout << num << " ";
    }
    
    return 0;
}
