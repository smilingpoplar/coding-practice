//
//  dungeon-game
//  https://leetcode.com/problems/dungeon-game/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        // 假设从[i,j]往右往下走到底，初始所需的最小血量为hp[i][j]：
        // 由hp[i][j] + dungeon[i][j] == min(hp[i+1][j], hp[i][j+1]) /*下一步选所需血量最少的那条路径*/
        // hp[i][j] = max(1 /*血量不能为0*/, min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j])
        const int M = dungeon.size(), N = dungeon[0].size();
        vector<vector<int>> hp(M, vector<int>(N, 0));
        hp[M-1][N-1] = max(1, 1 - dungeon[M-1][N-1]);
        for (int i = M - 2; i >= 0; i--) { // right
            hp[i][N-1] = max(1, hp[i+1][N-1] - dungeon[i][N-1]);
        }
        for (int j = N - 2; j >= 0; j--) { // bottom
            hp[M-1][j] = max(1, hp[M-1][j+1] - dungeon[M-1][j]);
        }
        for (int i = M - 2; i >= 0; i--) {
            for (int j = N - 2; j >= 0; j--) {
                hp[i][j] = max(1, min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j]);
            }
        }
        return hp[0][0];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    Solution solution;
    cout << solution.calculateMinimumHP(dungeon);

    return 0;
}
