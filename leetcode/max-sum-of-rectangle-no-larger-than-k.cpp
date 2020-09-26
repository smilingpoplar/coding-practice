//
//  max-sum-of-rectangle-no-larger-than-k
//  https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        const int R = matrix.size(), C = matrix[0].size();
        
        int ans = INT_MIN;
        for (int r1 = 0; r1 < R; r1++) {
            vector<int> sum(C, 0); // [r1,r2]行累加到sum中
            for (int r2 = r1; r2 < R; r2++) {
                for (int c = 0; c < C; c++) {
                    sum[c] += matrix[r2][c];
                }
                
                // 在sum[]中找<=k的子段和，滑动窗口解atMost问题
                int wsum = 0;
                for (int hi = 0, lo = 0; hi < C; hi++) {
                    wsum += sum[hi];
                    while (s > k) {
                        s -= wsum[lo++];
                    }
                    ans = max(ans, wsum);
                }
            }           
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
