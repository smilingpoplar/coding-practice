//
//  android-unlock-patterns
//  https://leetcode.com/problems/android-unlock-patterns/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        // 判断有效move的关键：3x3棋盘很小，跳过未选择数字的非法情况可以都记在表中
        vector<vector<int>> jump(10, vector<int>(10, -1));
        jump[1][3] = jump[3][1] = 2;
        jump[1][7] = jump[7][1] = 4;
        jump[3][9] = jump[9][3] = 6;
        jump[7][9] = jump[9][7] = 8;
        jump[1][9] = jump[9][1] = jump[2][8] = jump[8][2] 
            = jump[3][7] = jump[7][3] = jump[4][6] = jump[6][4] = 5;
        
        // 回溯法
        vector<bool> visited(10, false);
        int ans = 0;
        ans += countPatterns(1, 1, m, n, jump, visited) * 4; // 1、3、7、9位置对称
        ans += countPatterns(2, 1, m, n, jump, visited) * 4; // 2、4、6、8位置对称
        ans += countPatterns(5, 1, m, n, jump, visited);
        return ans;        
    }

    // num是当前选择的数字，pattLen是当前pattern长
    int countPatterns(int num, int pattLen, const int m, const int n, 
             const vector<vector<int>> &jump, vector<bool> &visited) {
        int ans = 0;
        dfs(num, pattLen, m, n, jump, visited, ans);
        return ans;
    }

    void dfs(int num, int pattLen, const int m, const int n, 
             const vector<vector<int>> &jump, vector<bool> &visited, int &pattCnt) {
        if (pattLen > n) return;
        if (pattLen >= m) pattCnt++; // 有效pattern：m<=pattLen<=n
        
        visited[num] = true;
        for (int next = 1; next <= 9; next++) {
            if (visited[next]) continue;
            int jumpNum = jump[num][next];
            if (jumpNum == -1 || visited[jumpNum]) { // 有效move：不需要跳过某数字，或被跳过的数字已访问
                dfs(next, pattLen + 1, m, n, jump, visited, pattCnt);
            }
        }
        visited[num] = false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
