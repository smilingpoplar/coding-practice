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
        int i = 0, j = (int)A.size() - 1;
        while (i < j) { // 把奇数往后抛
            if (A[i] & 1) {
                swap(A[i], A[j]);
                j--;
            } else {
                i++;
            }
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
