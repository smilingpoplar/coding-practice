//
//  minimum-deletion-cost-to-avoid-repeating-letters
//  https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        // 连续相同字符只剩cost最大的不删除
        const int N = s.size();
        int ans = 0, maxCost = 0;
        for (int i = 0; i < N; i++) {
            if (i > 0 && s[i] != s[i-1]) {
                ans -= maxCost;
                maxCost = 0;
            }
            maxCost = max(maxCost, cost[i]);
            ans += cost[i];
        }
        ans -= maxCost;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
