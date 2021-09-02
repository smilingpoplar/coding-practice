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
        // 分成和最接近的两个子集，求 和<=sum/2的最大子集，01背包
        // 设dp[i][v]表示前i个数的子集和等于v是否可行。
        // dp[i][v] = dp[i-1][v]/*不取nums[i]*/ || dp[i-1][v-num]/*取nums[i]*/。
        // 递推式i这维依赖于i-1项，可省掉i这一维。dp[v] = dp[v] || dp[v-num]。v逆序遍历。
        int sum = 0;
        for (int w : stones) 
            sum += w;
        
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
