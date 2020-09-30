//
//  minimum-falling-path-sum
//  https://leetcode.com/problems/minimum-falling-path-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int R = A.size(), C = A[0].size();
        for (int r = 1; r < R; r++) {
            for (int c = 0; c < C; c++) {
                A[r][c] = A[r][c] + min({c-1 >= 0 ? A[r-1][c-1] : INT_MAX, 
                                        A[r-1][c], 
                                        c+1 < C ? A[r-1][c+1] : INT_MAX});
            }
        }
        return *min_element(begin(A[C-1]), end(A[C-1]));
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
