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

        // 当前数B[i]-队首B[q[0]]表示子段和，要让子段和尽量大，队首要尽量小，B[q[x..]]是递增序列。
        // 队中数最终都要作为队首参与子段和计算，最短子段要求相同数只保留右边的，B[q[x..]]是严格递增序列

        int ans = INT_MAX;
        deque<int> q;
        for (int i = 0; i <= N; i++) {
            while (!q.empty() && B[i] - B[q[0]] >= K) { 
                ans = min(ans, i - q[0]);
                q.pop_front();
            }

            while (!q.empty() && B[i] <= B[q.back()]) { // 严格递增，出栈用<=比较
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
