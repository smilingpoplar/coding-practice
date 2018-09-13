//
//  strobogrammatic-number-iii
//  https://leetcode.com/problems/strobogrammatic-number-iii/
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
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        expand("", low, high, count); // n%2==0
        for (string s : {"0", "1", "8"}) { // n%2==1
            expand(s, low, high, count);
        }
        return count;
    }
    
    // 扩展num两端，添加数对
    void expand(string num, const string &low, const string &high, int &count) {
        const int len = num.size(), lowLen = low.size(), highLen = high.size();
        if (len > highLen) return; // 排除过长的
        if (len >= lowLen && !(len > 1 && num[0] == '0')) { // 长度合适，排除以‘0’开头的
            if (lowLen == highLen) {
                if (low <= num && num <= high) count++;
            } else {
                if ((len == lowLen && num >= low) || (len == highLen && num <= high) 
                    || (lowLen < len && len < highLen)) count++;
            }
        }

        for (auto &e : mp) {
            expand(e.first + num + e.second, low, high, count);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
