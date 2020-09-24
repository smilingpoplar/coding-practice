//
//  minimum-cost-for-tickets
//  https://leetcode.com/problems/minimum-cost-for-tickets/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // 设dp[i]表示day[1..i]的minCost。i不在days中时，dp[i]=dp[i-1]；否则，
        // dp[i] = min( dp[i-1]+costs[0], dp[max(0,i-7)]+costs[1], dp[max(0,i-30)]+costs[2] )
        unordered_set<int> ds(days.begin(), days.end());
        const int TOTAL_DAYS = 365;
        vector<int> dp(TOTAL_DAYS + 1);
        dp[0] = 0;
        
        for (int i = 1; i <= TOTAL_DAYS; i++) {
            if (!ds.count(i)) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = min({dp[i-1] + costs[0], 
                             dp[max(0,i-7)] + costs[1], 
                             dp[max(0,i-30)] + costs[2]});
            }
        }
        return dp[TOTAL_DAYS];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
