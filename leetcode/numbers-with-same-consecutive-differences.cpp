//
//  numbers-with-same-consecutive-differences
//  https://leetcode.com/problems/numbers-with-same-consecutive-differences/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ans;
        for (int num = 1; num <= 9; num++) {
            dfs(num, N - 1, K, ans);
        }
        return ans;
    }
    
    void dfs(int num, int N, int K, vector<int> &ans) {
        if (N == 0) {
            ans.push_back(num);
            return;
        }
        int d = num % 10;
        if (d + K <= 9) dfs(num * 10 + d + K, N - 1, K, ans);
        if (K > 0 && d - K >= 0) dfs(num * 10 + d - K, N - 1, K, ans);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
