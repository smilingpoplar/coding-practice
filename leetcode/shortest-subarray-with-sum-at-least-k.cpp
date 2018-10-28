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
        vector<int> B(N + 1, 0);
        for (int i = 1; i <= N; i++) 
            B[i] = B[i-1] + A[i-1];
        // B[i]表示sum{A[0..i)，B[i]-B[j]表示sum{A[j..i)}
        
        int ans = INT_MAX;
        deque<int> q;
        for (int i = 0; i <= N; i++) {
            while (!q.empty() && B[i] - B[q[0]] >= K) {
                ans = min(ans, i - q[0]);
                q.pop_front();
            }
            // 当前数B[i]-队首B[q[0]]表示子段和，要这子段和尽量大（为了>=K），队首放最小值，是递增队列。
            // 队中数最终都要作为队首参与子段和计算。若队中两个相等数B[x]==B[y]，x<y，
            // 参与计算时y比起x值相等、子段更短，x可以丢弃，即相等数只保留右边那个，是严格递增序列。
            while (!q.empty() && B[i] <= B[q.back()]) 
                q.pop_back();
            q.push_back(i);
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
