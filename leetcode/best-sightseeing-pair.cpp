//
//  best-sightseeing-pair
//  https://leetcode.com/problems/best-sightseeing-pair/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // 找一对数，使A[i]+A[j]+i-j最大，即(A[i]+i)+(A[j]-j)最大
        // 从左往右扫描，记住最大的A[i]+i
        const int N = A.size();
        int ans = 0, maxI = A[0] + 0;
        for (int j = 1; j < N; j++) {
            ans = max(ans, maxI + A[j] - j);
            maxI = max(maxI, A[j] + j);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
