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
    int shortestSubarray(vector<int>& A, int K) {
        // 求presum[i]-presum[j]>=K的最短子段长
        // 如果在presum[]数组中，presum[j]能找到下一个更小（或相等）的数presum[k]，
        // 因为presum[i]-presum[k]更大（或相等）、且子段更短，这时presum[j]就不用考虑。
        // 也就是说，我们只需考虑那些找不到下一个更小（或相等）的数的presum[j]，对应"找下一个更小的数"问题的单调递增序列。
        // 在这个单调递增序列上，用滑动窗口求子段和>=K的最短子段
        const int N = A.size();
        vector<long> presum(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            presum[i] = presum[i - 1] + A[i - 1];
        }

        int ans = INT_MAX;
        deque<int> dq;  // 滑动窗口
        for (int i = 0; i <= N; i++) {
            // 单调递增序列
            while (!dq.empty() && presum[i] <= presum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            while (!dq.empty() && presum[i] - presum[dq.front()] >= K) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
