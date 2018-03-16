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
        // 前n-1个数字的序列构成一个节点，共k^(n-1)个。每个节点指向以[0..k-1]开头的节点，即指向所有节点。
        // 这题就是要找一条遍历所有边的欧拉回路。因为这是个全连接图，每个节点的入度等于出度，所以存在欧拉回路。
        // 用边的后序遍历求逆欧拉路径，类似用点的后序遍历求逆拓扑序。用(节点+下一节点头)表示边。
        string src(n - 1, '0');
        unordered_set<string> visited;
        string ans;
        dfs(src, k, visited, ans);
        ans.append(src); // 用后序遍历
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
            ans.append(s); // 用后序遍历
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
