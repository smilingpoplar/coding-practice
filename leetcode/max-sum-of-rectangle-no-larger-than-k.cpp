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
        // 题目中说行数可能远大于列数，所以要按列求和
        int ans = INT_MIN;
        for (int c1 = 0; c1 < C; c1++) {
            vector<int> colSum(R, 0); // [c1..c2]列累加到colSum中
            for (int c2 = c1; c2 < C; c2++) {
                for (int r = 0; r < R; r++) {
                    colSum[r] += matrix[r][c2];
                }
                
                // 在colSum[]中找<=k的子段和
                set<int> st = {0};
                int runningSum = 0;
                for (int num : colSum) {
                    runningSum += num;
                    // runningSum-toFind<=k，toFind>=runningSum-k
                    auto it = st.lower_bound(runningSum - k);
                    if (it != st.end()) ans = max(ans, runningSum - *it);
                    if (ans == k) return k;//
                    st.insert(runningSum);
                }
            }           
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
