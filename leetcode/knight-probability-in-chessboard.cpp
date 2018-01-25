//
//  knight-probability-in-chessboard
//  https://leetcode.com/problems/knight-probability-in-chessboard/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // 设prob[i][j][steps]表示i行j列已跳steps步位置的概率，
        // prob[i][j][steps] = 来自8个位置的概率prob[i-dr][j-dc][steps-1]加和
        // prob[][][steps]只依赖于prob[][][steps-1]，可减掉一维
        // 设prev[][]表示第steps-1步的概率矩阵
        const vector<int> dr = { -2, -1, 1, 2,  2,  1, -1, -2 };
        const vector<int> dc = {  1,  2, 2, 1, -1, -2, -2, -1 };
        vector<vector<double>> prev(N, vector<double>(N, 0));
        prev[r][c] = 1;
        
        for (int k = 0; k < K; k++) {
            vector<vector<double>> cur(N, vector<double>(N, 0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int m = 0; m < dr.size(); m++) {
                        int pi = i - dr[m], pj = j - dc[m];
                        if (0 <= pi && pi < N && 0 <= pj && pj < N) {
                            cur[i][j] += prev[pi][pj] / 8;
                        }
                    }
                }
            }
            prev.swap(cur);
        }
        
        double ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans += prev[i][j];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
