//
//  nth-magical-number
//  https://leetcode.com/problems/nth-magical-number/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        const int MOD = 1e9 + 7;
        int lcm = A / gcd(A, B) * B;
        long l = min(A, B), u = (long)N * min(A, B);
        while (l <= u) {
            long mid = l + (u - l) / 2;
            if (enough(mid, A, B, lcm, N)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l % MOD;
    }

    int gcd(int A, int B) {
        while (B) {
            int tmpA = A;
            A = B;
            B = tmpA % B;
        }
        return A;
    }

    // "<=x的A,B倍数"count>=N吗？
    bool enough(long x, int A, int B, int lcm, int N) {
        return x / A + x / B - x / lcm >= N;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
