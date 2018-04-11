//
//  soup-servings
//  https://leetcode.com/problems/soup-servings/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double soupServings(int N) {
        if (N >= 5000) return 1; // trick：单调递增，N太大时直接返回1
        map<pair<int, int>, double> memo;
        return prob(N, N, memo);
    }
    
    double prob(int a, int b, map<pair<int, int>, double> &memo) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (memo.count({a, b})) return memo[{a, b}];
        
        vector<vector<int>> ops = { {100, 0}, {75, 25}, {50, 50}, {25, 75} };
        double ans = 0;
        for (auto &op : ops) {
            ans += 0.25 * prob(a - op[0], b - op[1], memo);
        }        
        memo[{a, b}] = ans;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
