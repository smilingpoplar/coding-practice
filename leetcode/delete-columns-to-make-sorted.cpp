//
//  delete-columns-to-make-sorted
//  https://leetcode.com/problems/delete-columns-to-make-sorted/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        const int R = A.size(), C = A[0].size();
        int ans = 0;
        for (int c = 0; c < C; c++) {
            for (int r = 0; r + 1 < R; r++) {
                if (A[r][c] > A[r+1][c]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
