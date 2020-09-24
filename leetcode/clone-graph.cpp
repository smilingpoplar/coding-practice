//
//  clone-graph
//  https://leetcode.com/problems/clone-graph/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        // 遍历并克隆
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        stack<UndirectedGraphNode *> stk;
        stk.push(node);
        
        while (!stk.empty()) {
            auto u = stk.top(); stk.pop();
            if (!copied[u]) copied[u] = new UndirectedGraphNode(u->label);
            
            for (auto v : u->neighbors) {
                if (!copied[v]) {
                    copied[v] = new UndirectedGraphNode(v->label);
                    stk.push(v);
                }
                copied[u]->neighbors.push_back(copied[v]);
            }
        }
        return copied[node];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
