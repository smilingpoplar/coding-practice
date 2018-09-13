//
//  strobogrammatic-number-ii
//  https://leetcode.com/problems/strobogrammatic-number-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    unordered_map<string, string> mp = { {"0","0"}, {"1","1"}, {"6","9"}, {"8","8"}, {"9","6"} };
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        if (n % 2 == 0) {
            expand("", n, ans);
        } else {
            for (string s : {"0", "1", "8"}) {
                expand(s, n, ans);
            }
        }
        return ans;
    }
    
    // 扩展num两端，添加数对
    void expand(string num, const int n, vector<string> &ans) {
        if (num.size() == n) {
            if (!(n > 1 && num[0] == '0')) ans.push_back(num);
            return;
        }
        
        for (auto &e : mp) {
            expand(e.first + num + e.second, n, ans);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
