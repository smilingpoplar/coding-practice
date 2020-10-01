//
//  maximum-profit-in-job-scheduling
//  https://leetcode.com/problems/maximum-profit-in-job-scheduling/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // 先按endTime排序
        const int N = startTime.size();
        vector<array<int, 3>> jobs;
        for (int i = 0; i < N; i++) {
            jobs.push_back({ endTime[i], startTime[i], profit[i] });
        }
        sort(begin(jobs), end(jobs));

        // 设dp[endTime]表示到某endTime的maxProfit
        map<int, int> dp; // endTime=>maxProfit
        dp[0] = 0; // 左哨兵
        for (auto& [e, s, p] : jobs) {
            // 对每个job找它前面与它相容的最后一个区间
            // 相容，即toFind.endTime<=cur.startTime
            int preMaxP = prev(dp.upper_bound(s))->second;
            int curMaxP = preMaxP + p;
            // 利润比已知更大，选择当前区间
            if (curMaxP > dp.rbegin()->second) dp[e] = curMaxP;
        }
        return dp.rbegin()->second;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
