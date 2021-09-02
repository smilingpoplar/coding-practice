//
//  last-stone-weight-ii
//  https://leetcode.com/problems/last-stone-weight-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 分成和最接近的两个子集
        // 不妨求 和<=sum/2的子集，01背包
        int sum = 0;
        for (int w : stones) 
            sum += w;
        
        // dp[v]表示能填满v容量
        vector<bool> dp(sum / 2, false);
        dp[0] = true;
        for (int w : stones) {
            for (int v = sum / 2; v >= w; v--) {
                dp[v] = dp[v] || dp[v-w];
            }
        }
        for (int v = sum / 2; v >= 0; v--) {
            if (dp[v]) return sum - v - v;
        } 
        return -1; // invalid
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
