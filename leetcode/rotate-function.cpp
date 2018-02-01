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
        // F(k)   = [  k,k+1,...,n-1,  0,...,k-1]*A
        // F(k-1) = [k-1,  k,...,n-2,n-1,...,k-2]*A
        // F(k) - F(k-1) = [1,1,...,1,1-n,...,1]*A = sum(A) - n*A[n-k]
        // F(k) = F(k-1) + sum - n*A[n-k]
        const int n = A.size();
        int sum = 0;
        int f = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            f += i * A[i];
        }

        int ans = f;
        for (int k = 1; k < n; k++) {
            f = f + sum - n * A[n-k];
            ans = max(ans, f);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
