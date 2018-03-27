//
//  number-of-connected-components-in-an-undirected-graph
//  https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        // 并查集
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        // unite
        for (auto &edge : edges) {
            int x = find(edge.first, parent);
            int y = find(edge.second, parent);
            if (x != y) {
                parent[x] = y;
                n--;
            }
        }
        return n;
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
