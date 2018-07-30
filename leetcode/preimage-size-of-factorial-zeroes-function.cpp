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
        // f(x)是x!末尾0的个数，取决于1..x中因子5的个数。
        // 因子5的个数每连续5个数相等，之后的5个数至少加1。所以只要f(x)=K的x存在，一定是有5个。
        // 二分搜索使f(x)=K的x，x的上限取5*K。因为x至少贡献x/5个因子5，5*K就可贡献K个因子5。
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
