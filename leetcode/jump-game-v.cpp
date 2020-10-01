//
//  jump-game-v
//  https://leetcode.com/problems/jump-game-v/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        // 题目：i跳到更小的高度j，(i..j)间的高度都比i处小，d是最大跳跃距离
        // 单调栈找波谷，找下一个更大的数
        const int N = arr.size();
        vector<vector<int>> graph(N);

        auto buildJumpGraph = [&](vector<int> &idx) {
            stack<int> stk; // 保存下标
            for (int i : idx) {
                while (!stk.empty() && arr[i] > arr[stk.top()]) {
                    int j = stk.top();
                    if (abs(i - j) <= d) graph[i].push_back(j); // 从i可跳到j
                    stk.pop();
                }
                stk.push(i);
            }
        };

        vector<int> idices(N);
        iota(begin(idices), end(idices), 0);
        buildJumpGraph(idices);
        reverse(begin(idices), end(idices));
        buildJumpGraph(idices);

        //现在从graph中找最长序列，dfs
        vector<int> memo(N, -1);
        function<int(int)> dfs = [&](int idx) {
            if (memo[idx] != -1) return memo[idx];
            int ans = 0;
            for (int adj : graph[idx]) {
                ans = max(ans, dfs(adj));
            }
            ans++;
            return memo[idx] = ans;
        };
        
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
