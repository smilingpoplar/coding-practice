//
//  partition-array-into-disjoint-intervals
//  https://leetcode.com/problems/partition-array-into-disjoint-intervals/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        // 只要max(left)<=min(right)就行
        const int N = A.size();
        vector<int> minR(N);
        minR[N-1] = A[N-1];
        for (int i = N - 2; i >= 0; i--) {
            minR[i] = min(A[i], minR[i+1]);
        }
        
        int maxL = A[0];
        for (int i = 1; i < N; i++) {
            if (maxL <= minR[i]) return i;
            maxL = max(maxL, A[i]);
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
