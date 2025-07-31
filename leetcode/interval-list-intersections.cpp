//
//  interval-list-intersections
//  https://leetcode.com/problems/interval-list-intersections/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        // 归并排序
        const int M = A.size(), N = B.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < M && j < N) {
            // 如果A[i]和B[j]相交，[lo,hi]是相交区间
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if (lo <= hi) ans.push_back({lo, hi});

            if (A[i][1] < B[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
