//
//  zuma-game
//  https://leetcode.com/problems/zuma-game/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        vector<int> handCount(128); // color=>count
        for (char c : hand) handCount[c]++;
        int ans = dfs(board, handCount);
        return ans != INT_MAX ? ans : -1;
    }
    
    int dfs(string &board, vector<int> &handCount) {
        if (board.empty()) return 0;
        int ans = INT_MAX;
        for (int i = 0, j; i < board.size(); i = j) { // 看从位置i开始能否删除同色球
            j = i;
            while (board[j] == board[i]) j++;
            int need = max(3 - (j - i), 0);
            if (need <= handCount[board[i]]) {
                handCount[board[i]] -= need;
                auto newBoard = clearConsecutives(board.substr(0, i) + board.substr(j)); // 删除[i..j-1]
                int remainStep = dfs(newBoard, handCount);
                if (remainStep != INT_MAX) ans = min(ans, need + remainStep);
                handCount[board[i]] += need;
            }
        }
        return ans;
    }
    
    string clearConsecutives(const string &board) {
        for (int i = 0, j; i < board.size(); i = j) {
            j = i;
            while (board[j] == board[i]) j++;
            if (j - i >= 3) return clearConsecutives(board.substr(0, i) + board.substr(j)); // 删除[i..j-1]
        }
        return board;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
