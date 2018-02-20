//
//  base-7
//  https://leetcode.com/problems/base-7/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        int n = abs(num);
        string ans;
        while (n) {
            ans.push_back(n % 7 + '0');
            n /= 7;
        }
        if (num < 0) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
