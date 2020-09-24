//
//  01-matrix
//  https://leetcode.com/problems/01-matrix/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> dist(R, vector<int>(C, INT_MAX));

        // 上=>下、左=>右
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] == 0) {
                    dist[r][c] = 0;
                } else {
                    if (r > 0 && dist[r-1][c] != INT_MAX) {
                        dist[r][c] = min(dist[r][c], dist[r-1][c] + 1);
                    }
                    if (c > 0 && dist[r][c-1] != INT_MAX) {
                        dist[r][c] = min(dist[r][c], dist[r][c-1] + 1);
                    }
                }
            }
        }        
        // 下=>上、右=>左
        for (int r = R - 1; r >= 0; r--) {
            for (int c = C - 1; c >= 0; c--) {
                if (matrix[r][c] != 0) {
                    if (r + 1 < R && dist[r+1][c] != INT_MAX) {
                        dist[r][c] = min(dist[r][c], dist[r+1][c] + 1);
                    }
                    if (c + 1 < C && dist[r][c+1] != INT_MAX) {
                        dist[r][c] = min(dist[r][c], dist[r][c+1] + 1);
                    }
                }
            }
        }
        return dist;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
