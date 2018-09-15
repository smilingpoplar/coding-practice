//
//  best-meeting-point
//  https://leetcode.com/problems/best-meeting-point/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        // 分维度考虑，在某个维度让各点相遇的路程
        if (grid.empty()) return 0;
        const int R = grid.size(), C = grid[0].size();
        vector<int> rows, cols;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c]) {
                    rows.push_back(r);
                    cols.push_back(c);
                }
            }
        }
        return minDist(rows) + minDist(cols);
    }
    
    int minDist(vector<int> &v) {
        int ans = 0;
        sort(v.begin(), v.end());
        int i = 0, j = (int)v.size() - 1;
        while (i < j) {
            ans += v[j--] - v[i++];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
