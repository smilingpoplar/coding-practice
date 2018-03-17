//
//  friend-circles
//  https://leetcode.com/problems/friend-circles/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 求连通图的个数，dfs
    int findCircleNum(vector<vector<int>>& M) {
        const int n = M.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(M, visited, i);
                count++;
            }
        }
        return count;        
    }

    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < M[i].size(); j++) {
            if (M[i][j] == 1 && !visited[j]) {
                dfs(M, visited, j);
            }
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
