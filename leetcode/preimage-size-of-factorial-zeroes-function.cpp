//
//  preimage-size-of-factorial-zeroes-function
//  https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int preimageSizeFZF(int K) {
        // f(x)是x!末尾0的个数，取决于1..x中因子5的个数
        // 因子5的个数每连续5个数的至少加1，存在5个连续数、它们的因子5个数相同，所以f(x)=K的x存在的话就有5个
        // 因为f(x)是个递增函数，用二分法看f(x)=K的x值存不存在
        long l = 0, u = 5l * K;
        while (l <= u) {
            long mid = l + (u - l) / 2;
            int count = countZeros(mid);
            if (count == K) return 5;
            else if (count > K) u = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
    
    int countZeros(long n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
