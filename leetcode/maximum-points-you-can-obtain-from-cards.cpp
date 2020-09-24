//
//  maximum-points-you-can-obtain-from-cards
//  https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // 变为：找长=N-k的最小子段和
        const int N = cardPoints.size();
        int totalSum = 0, subSum = 0, minSum = INT_MAX;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            totalSum += cardPoints[hi];
            subSum += cardPoints[hi];
            if (hi - lo + 1 > N - k) {
                subSum -= cardPoints[lo];
                lo++;
            } 
            if (hi - lo + 1 == N - k) {
                minSum = min(minSum, subSum);
            }
        }
        return totalSum - minSum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
