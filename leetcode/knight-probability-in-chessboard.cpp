//
//  knight-probability-in-chessboard
//  https://leetcode.com/problems/knight-probability-in-chessboard/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // 设prob[i][j][k]表示马在第i行j列、已跳k步的概率，
        // prob[i][j][k] = 来自8个位置的概率prob[i-dr][j-dc][k-1]的和
        // 递推式在k维只依赖k-1项，可省掉k维，k仍从左往右遍历
        const vector<array<int, 2>> d = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
                                          {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
        vector<vector<double>> prob(N, vector<double>(N, 0));
        prob[r][c] = 1;
        
        // 模拟走步更新概率分布
        for (int k = 1; k <= K; k++) {
            vector<vector<double>> nprob(N, vector<double>(N, 0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int m = 0; m < d.size(); m++) {
                        int pi = i - d[m][0], pj = j - d[m][1];
                        if (0 <= pi && pi < N && 0 <= pj && pj < N) {
                            nprob[i][j] += prob[pi][pj] / 8;
                        }
                    }
                }
            }
            swap(prob, nprob);
        }
        
        double ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans += prob[i][j];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
