//
//  preimage-size-of-factorial-zeroes-function
//  https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int preimageSizeFZF(int K) {
        // 题目：满足x!末尾刚好K个0的数x有多少个？

        // x!末尾0的个数等于因子5的个数，因子5的个数每连续5个数相等。
        // 因此，满足条件的x若存在就有5个，若不存在就0个。
        // 二分搜索猜x是否存在，x的上限取5K，因为5K可至少贡献5K/5=K个因子5。
        long l = 0, u = 5l * K;
        while (l <= u) {
            long mid = l + (u - l) / 2;
            int count = countZeros(mid);
            if (count == K) return 5;

            if (count > K) u = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
    
    int countZeros(long n) {
        int ans = 0;
        while (n /= 5) {
            ans += n;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
