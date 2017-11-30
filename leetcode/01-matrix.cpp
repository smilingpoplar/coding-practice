//
//  01-matrix
//  https://leetcode.com/problems/01-matrix/
//
//  Created by smilingpoplar on 17/11/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        vector<vector<int>> dist(M, vector<int>(N, INT_MAX));

        // top=>bottom, left=>right
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0 && dist[i - 1][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    }
                    if (j > 0 && dist[i][j - 1] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                    }
                }
            }
        }        
        // bottom=>top, right=>left
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (matrix[i][j] != 0) {
                    if (i + 1 < M && dist[i + 1][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                    }
                    if (j + 1 < N && dist[i][j + 1] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
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
