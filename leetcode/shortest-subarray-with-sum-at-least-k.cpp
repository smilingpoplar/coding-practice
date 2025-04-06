//
//  shortest-subarray-with-sum-at-least-k
//  https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int T) {
        // 求presum[i]-presum[j]>=T的最短子段长
        // 对于左端点presum[j]，如果在presum[]中能找到下一个更小（或相等）的数presum[k]，
        // 因为presum[i]-presum[k]更大（或相等）、且子段i-k更短，所以presum[k]占优。
        // 只需考虑占优选项，用单调栈
        // 配合两指针法
        const int N = A.size();
        vector<long> presum(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            presum[i] = presum[i - 1] + A[i - 1];
        }

        int ans = INT_MAX;
        deque<int> dq;
        for (int k = 0; k <= N; k++) {
            while (!dq.empty() && presum[k] <= presum[dq.back()]) {  // 只考虑占优策略
                dq.pop_back();
            }
            dq.push_back(k);

            while (!dq.empty() && presum[k] - presum[dq[0]] >= T) {
                ans = min(ans, k - dq[0]);
                dq.pop_front();  // dp[0]对后面的k都不会取得更短子段
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
