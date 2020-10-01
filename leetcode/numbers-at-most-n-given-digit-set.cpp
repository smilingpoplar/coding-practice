//
//  numbers-at-most-n-given-digit-set
//  https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // digits中有d个数（d进制），若取k个数构成k位数，有d^k个
        // 1. n是N位数，<N位的数有d^1+d^2+...+d^(N-1)个
        // 2. =N位且<n的数先看第一位strN[0]，有(digits[]中<strN[0]的个数)*d^(N-1)+(若可取到strN[0]，再看第二位...)
        //        = lessThanCnt(strN[0])*d^(N-1)+lessThanCnt(strN[1])*d^(N-2)+...lessThanCnt(strN[N-1])*d^0
        // 3. 若可取到n本身，再加上1
        const auto strN = to_string(n);
        const int d = digits.size(), N = strN.size();
        // case 1
        int base = 1, ans = 0;
        for (int i = 1; i < N; i++) {
            base *= d;
            ans += base;
        }
        // case 2
        vector<bool> hasDigit(10, false);
        vector<int> lessThanCnt(10, 0);
        for (auto &ch: digits) {
            int digit = ch[0] - '0';
            hasDigit[digit] = true;
            for (int i = digit + 1; i < 10; i++) 
              lessThanCnt[i]++;
        }
        
        int idx;
        for (idx = 0; idx < N; idx++) {
            int digit = strN[idx] - '0';
            ans += lessThanCnt[digit] * base;
            base /= d;
            if (!hasDigit[digit]) break;
        }
        // case 3
        if (idx == N) ans++;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
