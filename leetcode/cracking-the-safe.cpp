//
//  cracking-the-safe
//  https://leetcode.com/problems/cracking-the-safe/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        // 将n-1位数作为节点，共$k^{n-1}个节点$，每个节点有k条入边和k条出边。
        // 设当前数为$a_{1}a_{2}...a_{k}$，它的第i条入边来自$ia_{1}...a_{k-1}$，第o条出边指向$a_{2}..a_{k}o$。
        // 从一个节点沿着编号为x的边走向另一个节点，相当于输入了数字x。
        // 题目变成 要找遍历所有边的欧拉路径，相当于输入了$k^{n-1}*k=k^{n}$个数，即为所有可能的密码。
        // 有向图每个节点的入度==出度，故存在欧拉回路。

        // 用(节点+下一节点头)表示边，用visited记录访问过的边。
        string src(n - 1, '0');
        unordered_set<string> visited;
        string ans;
        dfs(src, k, visited, ans);
        ans += src; // 后序遍历
        // reverse(ans.begin(), ans.end()); // u->..->v..->v..->u，全连接图的欧拉回路正好对称
        return ans;
    }

    void dfs(const string &node, int k, unordered_set<string> &visited, string &ans) {
        for (int i = 0; i < k; i++) {
            auto x = to_string(i);
            auto edge = node + x;
            if (visited.count(edge)) continue;
            visited.insert(edge);
            dfs(edge.substr(1), k, visited, ans);
            ans += x; // 后序遍历
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
