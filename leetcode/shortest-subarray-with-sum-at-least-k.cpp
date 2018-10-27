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
        vector<int> sum(N + 1, 0); // sum[i]表示sum( A[0..i) )
        for (int i = 1; i <= N; i++) 
            sum[i] = sum[i-1] + A[i-1];
        
        int ans = INT_MAX;
        deque<int> q;
        for (int i = 0; i <= N; i++) {
            // sum( A[q[0]..i) )子段和
            while (!q.empty() && sum[i] - sum[q.front()] >= K) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            // 以i结尾的子段和，要给sum[i]在sum[..i)从后往前找满足"sum[i]-sum[j]>=K"的索引j。
            // 假设已找到索引j，那么j前面>=sum[j]的数都可以抛弃，因为子段变长、子段和sum[i]-sum[j]变小。
            // 所以要找下个更小的数，对应找波峰、栈中保留递增序列。
            while (!q.empty() && sum[i] <= sum[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
