//
//  minimum-add-to-make-parentheses-valid
//  https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
        int bal = 0, ans = 0;
        for (char c : S) {
            bal += (c == '(') ? 1 : -1;
            if (bal == -1) {
                bal++;
                ans++;
            }
        }
        ans += bal;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
