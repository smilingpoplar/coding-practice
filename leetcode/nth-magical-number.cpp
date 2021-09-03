//
//  nth-magical-number
//  https://leetcode.com/problems/nth-magical-number/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        // 猜第N小的A,B倍数为x，x的取值范围为[min(A,B), N*min(A,B)]
        const int MOD = 1e9 + 7;
        int lcm = A / __gcd(A, B) * B;
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

    bool enough(long x, int A, int B, int lcm, int N) {
        // count(x){ <=x的A,B倍数的个数}是关于x的递增函数
        // enough(x){ count(x)>=N }满足二分搜索的条件形式[0..0 1..1]
        // 而 count(x) = x/A + x/B - x/lcm(A,B)
        return x / A + x / B - x / lcm >= N;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
