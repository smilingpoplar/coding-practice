//
//  clone-graph
//  https://leetcode.com/problems/clone-graph/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        // 遍历并克隆
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        vector<UndirectedGraphNode *> stack;
        stack.push_back(node);
        while (!stack.empty()) {
            auto v = stack.back();
            stack.pop_back();
            
            if (!copied[v]) copied[v] = new UndirectedGraphNode(v->label);
            
            for (auto neighbor : v->neighbors) {
                if (!copied[neighbor]) {
                    copied[neighbor] = new UndirectedGraphNode(neighbor->label);
                    stack.push_back(neighbor);
                }
                copied[v]->neighbors.push_back(copied[neighbor]);
            }
        }
        return copied[node];
    }
};

void printGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode *, bool> visited;
    vector<UndirectedGraphNode *> stack;
    if (node) stack.push_back(node);
    while (!stack.empty()) {
        auto v = stack.back();
        stack.pop_back();
        visited[v] = true;
        cout << v->label << " ";
        for (auto neighbor : v->neighbors) {
            if (!visited[neighbor]) {
                stack.push_back(neighbor);
            }
        }
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    UndirectedGraphNode n0(0);
    UndirectedGraphNode n1(1);
    UndirectedGraphNode n2(2);
    n0.neighbors = {&n1, &n2};
    n1.neighbors = {&n2};
    n2.neighbors = {&n2};
    printGraph(&n0);
    
    Solution solution;
    auto clone = solution.cloneGraph(&n0);
    printGraph(clone);

    return 0;
}
