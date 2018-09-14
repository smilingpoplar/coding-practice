//
//  rotate-function
//  https://leetcode.com/problems/rotate-function/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        // F(k)乘积中右旋A，相当于左旋[0 1 ... n-1]
        // F(k)   = [  k k+1 ... n-1   0 1 ... k-1] * A
        // F(k-1) = [k-1   k ... n-2 n-1 0 ... k-2] * A
        // F(k) - F(k-1) = [1 1 ... 1 1-n 1 .. 1] * A = sum(A) - n*A[n-k]
        // F(k) = F(k-1) + sum(A) - n*A[n-k]
        const int n = A.size();
        int sum = 0;
        int F = 0; // F(k)只依赖于k-1项，降维，初始F(0)=sum(i*A[i])
        for (int i = 0; i < n; i++) {
            sum += A[i];
            F += i * A[i];
        }

        int ans = F;
        for (int k = 1; k < n; k++) {
            F += sum - n * A[n-k];
            ans = max(ans, F);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
