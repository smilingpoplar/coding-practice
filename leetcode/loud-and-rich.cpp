//
//  loud-and-rich
//  https://leetcode.com/problems/loud-and-rich/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // 返回ans[i]：同富或更富的人中 最安静的
        // 构造图，指向同富或更富有的人
        const int N = quiet.size();
        vector<vector<int>> adj(N);
        for (auto &e : richer) {
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (ans[i] == -1) dfs(i, adj, quiet, ans);
        }
        return ans;
    }
    
    int dfs(int idx, vector<vector<int>> &adj, vector<int> &quiet, vector<int> &ans) {
        // 后序遍历，ans[]充当memo
        if (ans[idx] != -1) return ans[idx];
        int qIdx = idx;
        for (int next : adj[idx]) {
            int cand = dfs(next, adj, quiet, ans);
            if (quiet[cand] < quiet[qIdx]) qIdx = cand;
        }
        ans[idx] = qIdx;
        return ans[idx];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
