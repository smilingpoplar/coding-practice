//
//  smallest-range-ii
//  https://leetcode.com/problems/smallest-range-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        // 为使max(B)-min(B)差值最小，要最小化max(B)、最大化min(B)
        // 先将A排序，前半段A[i]+K、后半段A[i]-K，可能使差值变小
        // 假设在位置i后分段，前半段最大值A[i]+K、最小值A[0]+K，后半段最大值A[N-1]-K、最小值A[i+1]-K
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        const int N = A.size();
        int ans = A[N-1] - A[0]; // 全加或全减
        for (int i = 0; i < N - 1; i++) { // 前半段加、后半段减
            int theMax = max(A[i] + K, A[N-1] - K);
            int theMin = min(A[0] + K, A[i+1] - K);
            ans = min(ans, theMax - theMin);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
