//
//  delete-columns-to-make-sorted-ii
//  https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // B初始各行都是空串，从A中选出一列，若将这列拼到B还能保持B各行有序，则选中这列拼入B。
        // 用isEqualPrefix[r]表示 B[r][已选列们]==B[r+1][已选列们]，这时A当前列的第r行还需比较。
        // 若!isEqualPrefix[r]，B[r][已选列们]<B[r+1][已选列们]，A当前列的第r行不用再比较。
        const int R = A.size(), C = A[0].size();
        vector<bool> isEqualPrefix(R, true);
        int ans = 0;
        for (int c = 0; c < C; c++) {
            // c列若删除，就对isEqualPrefix[]无影响
            bool deleteC = false;
            for (int r = 0; r + 1 < R; r++) {
                if (isEqualPrefix[r] && A[r][c] > A[r+1][c]) {
                    deleteC = true;
                    ans++;
                    break;
                }
            }
            
            if (!deleteC) {
                for (int r = 0; r + 1 < R; r++) {
                    if (A[r][c] < A[r+1][c]) {
                        isEqualPrefix[r] = false;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
