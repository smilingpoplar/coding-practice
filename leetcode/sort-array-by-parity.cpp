//
//  sort-array-by-parity
//  https://leetcode.com/problems/sort-array-by-parity/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // 把偶数往前抛
        for (int r = 0, w = 0; r < A.size(); r++) {
            if (A[r] % 2 == 0) swap(A[r], A[w++]);
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
