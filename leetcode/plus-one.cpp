//
//  plus-one
//  https://leetcode.com/problems/plus-one/
//
//  Created by smilingpoplar on 15/5/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int N = digits.size();
        int carry = 1;
        for (int i = N - 1; i >= 0 && carry > 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> digits = {1, 0, 9};
    Solution solution;
    auto result = solution.plusOne(digits);
    for (auto digit : result) {
        cout << digit;
    }
    
    return 0;
}
