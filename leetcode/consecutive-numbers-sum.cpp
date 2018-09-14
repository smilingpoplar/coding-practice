//
//  consecutive-numbers-sum
//  https://leetcode.com/problems/consecutive-numbers-sum/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        // 假设N可分成k个连续数之和：N=x+(x+1)+(x+2)+...+(x+k-1)=k*x+k*(k-1)/2，
        // k*x = N-k*(k-1)/2。x是>=1的整数 => (N-k*(k-1)/2)%k==0 且 k(k+1)<=2*N。
        int ans = 0;
        for (int k = 1; k * (k + 1) <= 2 * N; k++) {
            if ((N - k * (k - 1) / 2) % k == 0) ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
