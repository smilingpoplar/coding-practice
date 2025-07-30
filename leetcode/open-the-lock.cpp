//
//  open-the-lock
//  https://leetcode.com/problems/open-the-lock/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // "0000"->"9999"共1w个节点的图，4个数字都可正反转动，所以节点有8个邻居
        // bfs找最短路径
        set<string> dead(begin(deadends), end(deadends));
        queue<string> q;
        q.push("0000");

        set<string> seen;
        int turn = 0;
        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                auto node = q.front();
                q.pop();
                if (seen.count(node) || dead.count(node)) continue;
                seen.insert(node);
                if (node == target) return turn;

                for (int i = 0; i < 4; i++) {
                    for (int d = -1; d <= 1; d += 2) {
                        string next(node);
                        next[i] = (node[i] - '0' + d + 10) % 10 + '0';
                        q.push(next);
                    }
                }
            }
            turn++;
        }

        return -1;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
