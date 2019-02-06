//
//  shortest-subarray-with-sum-at-least-k
//  https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int N = A.size();
        // B[i]表示sum{A[0..i)}，B[i]-B[j]表示sum{A[j..i)}
        vector<int> B(N + 1, 0);
        for (int i = 0; i < N; i++) {
            B[i+1] = B[i] + A[i];
        }
        
        // 当前数B[i]-队首B[q[0]]表示子段和；要让子段和尽量大，队首尽量小，是递增队列。
        // 因为q是递增序列，若B[i]-B[q[0]]>=K，i-q[0]就是以q[0]开头的子段中最短的，q[0]用完即弃。
        // 若q中相邻两数x<y，B[x]==B[y]，作为队首参与计算时y对应子段更短，相等数只保留右边的，
        // 所以是严格递增队列，出栈比较用<=。
        int ans = INT_MAX;
        deque<int> q;
        for (int i = 0; i <= N; i++) {
            while (!q.empty() && B[i] - B[q[0]] >= K) {
                ans = min(ans, i - q[0]);
                q.pop_front(); // q[0]用完即弃
            }

            while (!q.empty() && B[i] <= B[q.back()]) { // 出栈比较用<=
                q.pop_back();
            }     
            q.push_back(i);
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
