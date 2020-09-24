//
//  knight-dialer
//  https://leetcode.com/problems/knight-dialer/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int knightDialer(int N) {
        const int MOD = 1e9 + 7;
        // 各数字可以跳到哪些数字
        vector<vector<int>> jump = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
            {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
        };
        // cnt[]记录以各数字结尾的拨号个数
        vector<int> cnt(10, 1);
        for (int i = 1; i < N; i++) { // 跳N-1次
            vector<int> ncnt(10, 0);
            for (int d = 0; d < 10; d++) {
                for (int nd : jump[d]) {
                    ncnt[nd] = (ncnt[nd] + cnt[d]) % MOD;
                }
            }
            swap(ncnt, cnt);
        }
        
        int ans = 0;
        for (int x : cnt) {
            ans = (ans + x) % MOD;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
