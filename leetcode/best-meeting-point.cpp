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
        // 分维度考虑，在一个维度上（x维或y维）各点相遇，可算出这个维度上所有点的距离
        if (grid.empty()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();
        vector<int> X;
        vector<int> Y;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 1) {
                    X.push_back(c);
                    Y.push_back(r);
                }
            }
        }
        return minDist(X) + minDist(Y);
    }
    
    int minDist(vector<int> &list) {
        int ans = 0;
        sort(list.begin(), list.end());
        int i = 0, j = list.size() - 1;
        while (i < j) {
            ans += list[j--] - list[i++];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
