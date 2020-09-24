//
//  valid-mountain-array
//  https://leetcode.com/problems/valid-mountain-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        const int N = A.size();
        int i = 0, j = N - 1;
        while (i + 1 < N && A[i] < A[i+1]) i++;
        while (j > 0 && A[j] < A[j-1]) j--;
        return i > 0 && j < N - 1 && i == j;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
