//
//  champagne-tower
//  https://leetcode.com/problems/champagne-tower/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // 模拟，设glass[r][c]表示第r行c列的杯子酒量
        int rowCnt = query_row + 2; // 要计算到第query_row+1行
        vector<vector<double>> glass(rowCnt, vector<double>(rowCnt, 0)); // 第i行有i+1个杯子
        glass[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            bool overflowRow = false;
            for (int j = 0; j < i + 1; j++) {
                if (glass[i][j] > 1) {
                    overflowRow = true;
                    double halfOverflow = (glass[i][j] - 1) / 2;
                    glass[i][j] = 1;
                    glass[i+1][j] += halfOverflow;
                    glass[i+1][j+1] += halfOverflow;
                }
            }
            if (!overflowRow) break;
        }
        return glass[query_row][query_glass];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
