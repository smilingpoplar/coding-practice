//
//  score-after-flipping-matrix
//  https://leetcode.com/problems/score-after-flipping-matrix/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        // 2^n > 2^(n-1) + 2^(n-2) + ... + 1 = 2^n-1，越高位贡献越大。
        // 所以 行先翻转，使首列都为1；非首列再翻转，使该列更多1。
        // 不做实际的翻转，假想首列已变为1，后面列的某格是否为1根据A[r][c]==A[r][0]判断。
        if (A.empty()) return 0;
        const int R = A.size(), C = A[0].size();
        int ans = 0;
        for (int c = 0; c < C; c++) {
            int col1s = 0; // 某列有多少个1
            for (int r = 0; r < R; r++) {
                col1s += A[r][c] == A[r][0];
            }
            col1s = max(col1s, R - col1s);
            int score = 1 << (C - 1 - c); // 某列的1代表多少分
            ans += col1s * score;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
