//
//  numbers-at-most-n-given-digit-set
//  https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        // D中有d个数、若取k个数构成k位数，有d^k个
        // 1. N是n位数，<n位的数有d^1+d^2+...+d^(n-1)个
        // 2. =n位且<N的数先看第一位a[0]，有(D中<a[0]的个数)*d^(n-1)+(若可取到a[0]，再看第二位...)
        //        = lessCnt(a[0])*d^(n-1)+lessCnt(a[1])*d^(n-2)+...lessCnt(a[n-1])*d^0
        // 3. 若可取到N本身，再加上1
        const auto NS = to_string(N);
        const int d = D.size(), n = NS.size();
        // case 1
        int base = 1, ans = 0;
        for (int i = 1; i < n; i++) {
            base *= d;
            ans += base;
        }

        // case 2
        vector<bool> hasDigit(10, false);
        vector<int> lessCnt(10, 0);
        for (auto &digitS: D) {
            int digit = digitS[0] - '0';
            hasDigit[digit] = true;
            for (int i = digit + 1; i < 10; i++) 
              lessCnt[i]++;
        }
        
        int idx;
        for (idx = 0; idx < n; idx++) {
            int digit = NS[idx] - '0';
            ans += lessCnt[digit] * base;
            base /= d;
            if (!hasDigit[digit]) break;
        }
        // case 3
        if (idx == n) ans++;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
