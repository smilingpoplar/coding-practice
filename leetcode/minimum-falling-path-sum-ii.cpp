//
//  minimum-falling-path-sum-ii
//  https://leetcode.com/problems/minimum-falling-path-sum-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        // arr[r][c] += min( arr[r-1][notC] )
        // min(arr[r-1][notC])只要记录最小值min1、最小值索引min1Idx，次小值min2
        const int R = arr.size(), C = arr[0].size();
        int min1 = 0, min1Idx = -1, min2 = 0;
        for (int r = 0; r < R; r++) {
            int tmp_min1 = INT_MAX, tmp_min1Idx = -1, tmp_min2 = INT_MAX;
            for (int c = 0; c < C; c++) {
                arr[r][c] += (c != min1Idx) ? min1 : min2;
                if (arr[r][c] < tmp_min1) {
                    tmp_min2 = tmp_min1;
                    tmp_min1 = arr[r][c];
                    tmp_min1Idx = c;
                } else if (arr[r][c] < tmp_min2) {
                    tmp_min2 = arr[r][c];
                }
            }
            min1 = tmp_min1, min1Idx = tmp_min1Idx, min2 = tmp_min2;
        }
        return *min_element(begin(arr[R-1]), end(arr[R-1]));
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
