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
        for (auto &v : mines) {
            grid[v[0]][v[1]] = 0;
        }

        vector<vector<int>> order(N, vector<int>(N, INT_MAX));
        // 看各点往左能延伸多长、往右能延伸多长
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                count = (grid[i][j] == 0) ? 0 : ++count;
                if (count < order[i][j]) order[i][j] = count;
            }
            count = 0;
            for (int j = N - 1; j >= 0; j--) {
                count = (grid[i][j] == 0) ? 0 : ++count;
                if (count < order[i][j]) order[i][j] = count;
            }

        }        
        // 看各点往上能延伸多长、往下能延伸多长
        int ans = 0;
        for (int j = 0; j < N; j++) {
            int count = 0;
            for (int i = 0; i < N; i++) {
                count = (grid[i][j] == 0) ? 0 : ++count;
                if (count < order[i][j]) order[i][j] = count;
            }
            count = 0;
            for (int i = N - 1; i >= 0; i--) {
                count = (grid[i][j] == 0) ? 0 : ++count;
                if (count < order[i][j]) order[i][j] = count;
                ans = max(ans, order[i][j]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
