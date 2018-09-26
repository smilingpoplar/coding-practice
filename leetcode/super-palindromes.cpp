//
//  super-palindromes
//  https://leetcode.com/problems/super-palindromes/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        // 若palin是回文，再看palin^2是否是回文
        // palin^2 <= R < 10^18，palin < 10^9
        // 生成palin只需k正反拼接（最后一位可重合），k < 10^5
        const long l = stol(L), r = stol(R);
        int ans = 0;
        countIfLengthOdd(true, l, r, ans);
        countIfLengthOdd(false, l, r, ans);
        return ans;
    }
    
    void countIfLengthOdd(bool odd, long l, long r, int &ans) {
        for (int k = 1; k < 1e5; k++) {
            auto s = to_string(k);
            string rs(s.rbegin(), s.rend());
            s += odd ? rs.substr(1) : rs;
            long v = stol(s);
            v *= v;
            if (v > r) break;
            if (l <= v && isPalin(to_string(v))) ans++;
        }
    }
    
    bool isPalin(const string &s) {
        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
