//
//  projection-area-of-3d-shapes
//  https://leetcode.com/problems/projection-area-of-3d-shapes/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int N = grid.size();
        
        int ans = 0;
        vector<int> rowMax(N, 0), colMax(N, 0);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] > 0) ans++; // top
                rowMax[r] = max(rowMax[r], grid[r][c]);
                colMax[c] = max(colMax[c], grid[r][c]);
            }
        }
        for (int i = 0; i < N; i++) {
            ans += rowMax[i];
            ans += colMax[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
