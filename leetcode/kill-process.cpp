//
//  kill-process
//  https://leetcode.com/problems/kill-process/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < pid.size(); i++) {
            adj[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> ans;
        preorder(kill, adj, ans);
        return ans;
    }
    
    void preorder(int kill, unordered_map<int, vector<int>> &adj, vector<int> &ans) {
        ans.push_back(kill);
        for (int child : adj[kill]) {
            preorder(child, adj, ans);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
