//
//  image-overlap
//  https://leetcode.com/problems/image-overlap/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        // 所有卷积一起一步步算
        const int N = A.size();
        vector<vector<int>> conv(2 * N - 1, vector<int>(2 * N - 1, 0));
        
        for (int r1 = 0; r1 < N; r1++) {
            for (int c1 = 0; c1 < N; c1++) {
                if (A[r1][c1] == 1) {
                    for (int r2 = 0; r2 < N; r2++) {
                        for (int c2 = 0; c2 < N; c2++) {
                            if (B[r2][c2] == 1) {
                                // r1-r2或c1-c2相等的累加到一起
                                // -N < r1-r2 < N
                                conv[r1-r2+N-1][c1-c2+N-1] += 1;
                            }
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for (int r = 0; r < 2 * N - 1; r++) {
            for (int c = 0; c < 2 * N - 1; c++) {
                ans = max(ans, conv[r][c]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
