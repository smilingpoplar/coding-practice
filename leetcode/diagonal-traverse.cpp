//
//  diagonal-traverse
//  https://leetcode.com/problems/diagonal-traverse/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        const int M = matrix.size();
        const int N = matrix[0].size();
        vector<int> ans;
        int r = 0, c = 0;
        for (int i = 0; i < M * N; i++) {
            ans.push_back(matrix[r][c]);
            if ((r + c) % 2 == 0) { // 向右上运动
                if (c == N - 1) { // 考虑右上角，要先判断c
                    r++;
                } else if (r == 0) {
                    c++;
                } else {
                    r--;
                    c++;
                }
            } else { // 向左下运动
                if (r == M - 1) { // 考虑左下角，要先判断r
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

int main(int argc, const char * argv[]) {
    return 0;
}
