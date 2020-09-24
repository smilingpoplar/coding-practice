//
//  sort-array-by-parity-ii
//  https://leetcode.com/problems/sort-array-by-parity-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        const int N = A.size();
        for (int i = 0, j = 1; i < N; i += 2, j += 2) {
            while (i < N && A[i] % 2 == 0) i += 2;
            while (j < N && A[j] % 2 == 1) j += 2;
            if (i < N) swap(A[i], A[j]);
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
