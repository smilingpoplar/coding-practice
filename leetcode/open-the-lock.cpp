//
//  open-the-lock
//  https://leetcode.com/problems/open-the-lock/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // "0000"->"9999"共1w个节点的图，4个数字都可正反转动，所以每节点有8个邻居，bfs找最短路径
        set<string> dead(deadends.begin(), deadends.end());
        queue<string> q;
        auto start = "0000";
        q.push(start);
        set<string> visited;
        visited.insert(start);

        int turn = 0;
        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                auto node = q.front(); q.pop();
                if (dead.count(node)) continue;
                if (node == target) return turn;
                
                for (int i = 0; i < 4; i++) {
                    for (int d = -1; d <= 1; d += 2) {
                        string neighbor(node);
                        neighbor[i] = (node[i] - '0' + d + 10) % 10 + '0';
                        if (!visited.count(neighbor)) {
                            q.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }
                }
            }
            turn++;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
