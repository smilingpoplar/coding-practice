//
//  diagonal-traverse
//  https://leetcode.com/problems/diagonal-traverse/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        const int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> diags(R + C - 1);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                diags[r+c].push_back(matrix[r][c]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < diags.size(); i++) {
            if (i % 2 == 0) {
                ans.insert(end(ans), rbegin(diags[i]), rend(diags[i]));
            } else {
                ans.insert(end(ans), begin(diags[i]), end(diags[i]));
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        const int R = matrix.size(), C = matrix[0].size();
        vector<int> ans;
        int r = 0, c = 0;
        for (int i = 0; i < R * C; i++) {
            ans.push_back(matrix[r][c]);
            if ((r + c) % 2 == 0) { // 向右上运动
                if (c == C - 1) { // 考虑右上角，要先r++
                    r++;
                } else if (r == 0) {
                    c++;
                } else {
                    r--;
                    c++;
                }
            } else { // 向左下运动
                if (r == R - 1) { // 考虑左下角，要先c++
                    c++;
                } else if (c == 0) {
                    r++;
                } else {
                    r++;
                    c--;
                }
            }
        }
        return ans;        
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
