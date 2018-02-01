//
//  max-sum-of-rectangle-no-larger-than-k
//  https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        int ans = INT_MIN;
        for (int r1 = 0; r1 < M; r1++) {
            vector<int> sum(N, 0);
            for (int r2 = r1; r2 < M; r2++) {
                for (int c = 0; c < N; c++) {
                    sum[c] += matrix[r2][c];
                }
                
                // 在sum[]中找<=k的子段和
                int runningSum = 0; // 初始空集和
                set<int> S;
                S.insert(runningSum);
                for (int num : sum) {
                    runningSum += num;
                    // 在S中找最小的x，使runningSum-x<=k，x>=runningSum-k
                    auto it = S.lower_bound(runningSum - k);
                    if (it != S.end()) ans = max(ans, runningSum - *it);
                    S.insert(runningSum);
                }
            }           
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}