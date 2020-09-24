//
//  number-of-operations-to-make-network-connected
//  https://leetcode.com/problems/number-of-operations-to-make-network-connected/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // n个节点用n-1条边能连通
        if (connections.size() < n - 1) return -1;
        // 数连通子图数count，需要移动count-1条边
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int count = n;
        for (auto &conn : connections) {
            int x = find(conn[0], parent);
            int y = find(conn[1], parent);
            if (x != y) {
                count--;
                parent[y] = x;
            }
        }
        return count - 1;
    }
    
    int find(int x, vector<int> &parent) {
        if (parent[x] != x) 
            parent[x] = find(parent[x], parent);
        return parent[x];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
