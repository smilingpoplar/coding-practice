//
//  open-the-lock
//  https://leetcode.com/problems/open-the-lock/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // "0000"->"9999"共1w个节点的图，4个数字都可正反转动，所以每节点有8个邻居，bfs找最短路径
        set<string> dead(deadends.begin(), deadends.end());
        set<string> visited;
        queue<string> q;
        q.push("0000");

        int turn = 0;
        while (!q.empty()) {
            for (int n = q.size(); n > 0; n--) {
                auto node = q.front();  q.pop();
                if (visited.count(node)) continue;
                visited.insert(node);
                if (dead.count(node)) continue;
                if (node == target) return turn;
                
                for (int i = 0; i < 4; i++) {
                    for (int d = -1; d <= 1; d += 2) {
                        auto neighbor = node;
                        neighbor[i] = (node[i] - '0' + d + 10) % 10 + '0';
                        q.push(neighbor);
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
