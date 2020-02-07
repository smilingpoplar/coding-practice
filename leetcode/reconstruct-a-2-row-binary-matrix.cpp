//
//  reconstruct-a-2-row-binary-matrix
//  https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        const int N = colsum.size();
        vector<vector<int>> ans(2, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            if (colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
            } else if (colsum[i] == 1) {
                if (upper > lower) ans[0][i] = 1;
                else ans[1][i] = 1;
            }
            upper -= ans[0][i], lower -= ans[1][i];
        }
        if (upper == 0 && lower == 0) return ans;
        return {};
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
