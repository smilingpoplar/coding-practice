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
        // 前缀和+单调栈
        // 假设i<j，要满足presum[j]-presum[i]>=K，需要最小化j-i
        // 1. 固定j最大化i，假设i1<i2<j，presum[i1]>=presum[i2]（注意有＝）
        // i2比i1更好，因为如果(i1,j)满足条件，(i2,j)的和更大、子段更短
        // 所以i1不用保留，当presum[i2]<=presum[i1]时i1出栈（严格单调递增栈）
        // 2. 固定i最小化j，假设i<j1<j2，presum[j1]-i>=K
        // j2比j1更差，因为(i,j2)子段更长（即使满足presum[j2]-i>=K，更何况可能不满足）
        // 所以从左往右找到一个满足条件的j1后，所有j2不用再考虑，i不用再保留，i出栈
        const int N = A.size();
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + A[i];
        }
        
        int ans = INT_MAX;
        deque<int> q;
        for (int i = 0; i <= N; i++) {
            // 1 严格单调递增栈
            while (!q.empty() && presum[i] <= presum[q.back()]) {
                q.pop_back();
            }     
            q.push_back(i);
            
            // 2 从左往右，找满足presum[j]-stackTop>=K的索引j，找到后i出栈
            while (!q.empty() && presum[i] - presum[q.front()] >= K) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
