//
//  add-strings
//  https://leetcode.com/problems/add-strings/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            if (i >= 0) carry += num1[i--] - '0';
            if (j >= 0) carry += num2[j--] - '0';
            ans.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
