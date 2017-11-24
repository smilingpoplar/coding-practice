//
//  arithmetic-slices
//  https://leetcode.com/problems/arithmetic-slices/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sum = 0;
        int dp = 0;
        for (int i = 2; i < A.size(); i++) {
          if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
              dp = dp + 1;
              sum += dp;
          } else {
              dp = 0;
          }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
