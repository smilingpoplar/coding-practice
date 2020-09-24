//
//  shortest-subarray-with-sum-at-least-k
//  https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        // 前缀和+可取最小值的单调队列
        // 假设i<j，要满足presum[j]-presum[i]>=K，且最小化j-i
        // 1. 固定j最大化i，假设i1<i2<j，presum[i2]<=presum[i1]（注意有＝）
        // i2比i1更好，因为如果(i1,j)满足大小条件，(i2,j)更满足、子段更短，所以i1不用保留
        // 2. 固定i最小化j，假设i<j1<j2，presum[j1]-presum[i]>=K
        // j2比j1更差，因为(i,j2)子段更长（即使满足presum[j2]-presum[i]>=K，更何况可能不满足）
        // 所以从左往右找到一个满足条件的j1后，所有j2不用再考虑，i用完不再保留
        const int N = A.size();
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + A[i];
        }
        
        int ans = INT_MAX;
        deque<int> dq;
        for (int i = 0; i <= N; i++) {
            // 1 可取最小值->单调递增；最短->相同值只保留最后一个->弹出比较用<=
            while (!dq.empty() && presum[i] <= presum[dq.back()]) {
                dq.pop_back();
            }     
            dq.push_back(i);
            
            // 2 从左往右，当前数跟队头比较
            while (!dq.empty() && presum[i] - presum[dq[0]] >= K) {
                ans = min(ans, i - dq[0]); // 前开后闭区间
                dq.pop_front();
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
