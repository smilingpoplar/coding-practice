//
//  sparse-matrix-multiplication
//  https://leetcode.com/problems/sparse-matrix-multiplication/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        // 这题A、B虽说是稀疏数组，但没按稀疏数组的格式存储，还是普通矩阵
        // 普通矩阵乘法：C[i][j] = A[i][k]*B[k][j]，这里把k循环外移，尽早跳过为0的项
        if (A.empty() || B.empty()) return {};
        const int I = A.size(), K = A[0].size(), J = B[0].size();
        vector<vector<int>> C(I, vector<int>(J, 0));
        for (int i = 0; i < I; i++) {
            for (int k = 0; k < K; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < J; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
