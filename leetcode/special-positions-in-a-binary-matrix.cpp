//
//  special-positions-in-a-binary-matrix
//  https://leetcode.com/problems/special-positions-in-a-binary-matrix/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int R = mat.size(), C = mat[0].size();
        vector<int> rows(R, 0), cols(C, 0);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (mat[r][c] == 1) {
                    rows[r]++;
                    cols[c]++;
                }
            }
        }
        int ans = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (mat[r][c] == 1 && rows[r] == 1 && cols[c] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
