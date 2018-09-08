//
//  cracking-the-safe
            //  https://leetcode.com/problems/cracking-the-safe/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        // 前n-1个数字的序列构成节点，共k^(n-1)个。每个节点指向去掉开头、再拼上[0..k-1]中某数的节点，即指向所有节点。
        // 要找出遍历所有边的欧拉路径。因为这是个全连接图，有向图每个节点的入度等于出度，所以存在欧拉回路。
        // 用(节点+下一节点头)表示边，用visited记录访问过的边。
        string src(n - 1, '0');
        unordered_set<string> visited;
        string ans;
        dfs(src, k, visited, ans);
        ans += src; // 后序遍历
        // reverse(ans.begin(), ans.end()); // u->..->v..->v..->u，全连接图的欧拉回路正好对称
        return ans;
    }
    
    void dfs(const string &state, int k, unordered_set<string> &visited, string &ans) {
        for (int i = 0; i < k; i++) {
            auto s = to_string(i);
            auto edge = state + s;
            if (visited.count(edge)) continue;
            visited.insert(edge);
            dfs(edge.substr(1), k, visited, ans);
            ans += s; // 后序遍历
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
