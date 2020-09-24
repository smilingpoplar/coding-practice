//
//  super-palindromes
//  https://leetcode.com/problems/super-palindromes/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        // 对于回文palin，若palin^2也是回文则palin^2是superpalin。
        // palin^2 <= R < 10^18，palin < 10^9（九位数）
        // 可用数k正反拼接生成palin（最后一位可重合），k < 10^5
        const long l = stol(L), r = stol(R);
        int ans = 0;
        countIfOddLen(true, l, r, ans);
        countIfOddLen(false, l, r, ans);
        return ans;
    }
    
    void countIfOddLen(bool odd, long l, long r, int &ans) {
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
