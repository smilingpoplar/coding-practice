//
//  largest-plus-sign
//  https://leetcode.com/problems/largest-plus-sign/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (auto &m : mines) {
            grid[m[0]][m[1]] = 0;
        }

        vector<vector<int>> order(N, vector<int>(N, INT_MAX));
        // 看各点往左能延伸多长、往右能延伸多长
        for (int r = 0; r < N; r++) {
            int count = 0;
            for (int c = 0; c < N; c++) {
                count = (grid[r][c] == 0) ? 0 : ++count;
                if (count < order[r][c]) order[r][c] = count;
            }
            count = 0;
            for (int c = N - 1; c >= 0; c--) {
                count = (grid[r][c] == 0) ? 0 : ++count;
                if (count < order[r][c]) order[r][c] = count;
            }

        }        
        // 看各点往上能延伸多长、往下能延伸多长
        int ans = 0;
        for (int c = 0; c < N; c++) {
            int count = 0;
            for (int r = 0; r < N; r++) {
                count = (grid[r][c] == 0) ? 0 : ++count;
                if (count < order[r][c]) order[r][c] = count;
            }
            count = 0;
            for (int r = N - 1; r >= 0; r--) {
                count = (grid[r][c] == 0) ? 0 : ++count;
                if (count < order[r][c]) order[r][c] = count;
                ans = max(ans, order[r][c]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
