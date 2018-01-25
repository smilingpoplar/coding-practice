//
//  triangle
//  https://leetcode.com/problems/triangle/
//
//  Created by smilingpoplar on 15/6/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // 动态规划，f(i,j)表示从t[0][0]到t[i][j]的最小路径和，
        // f(i,j) = min( f(i-1,j-1), f(i-1,j) ) + t[i][j]，1<=j<i<=N-1
        // f(i,j) = f(i-1,j) + t[i][j]，j==0；f(i,j) = f(i-1,j-1) + t[i][j]，j==i
        // 通项式只依赖于前一组，在i的递增循环j的递减循环中降维，
        // f(j) = min( f(j-1),f(j) ) + t[i][j]，1<=j<i<=N-1
        // f(j) = f(j) + t[i][j]，j==0；f(j) = f(j-1) + t[i][j]，j==i
        if (triangle.empty()) return 0;
        const int N = (int)triangle.size();
        vector<int> f(N, 0);
        f[0] = triangle[0][0];
        for (int i = 1; i < N; i++) {
            f[i] = f[i - 1] + triangle[i][i]; // j==i
            for (int j = i - 1; j >= 1; j--) { // i>=2进循环
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            f[0] = f[0] + triangle[i][0]; //j==0
        }

        int minTotal = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (f[j] < minTotal) minTotal = f[j];
        }
        return minTotal;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    Solution solution;
    cout << solution.minimumTotal(triangle);

    return 0;
}
