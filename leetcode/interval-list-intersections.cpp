//
//  interval-list-intersections
//  https://leetcode.com/problems/interval-list-intersections/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        // 归并排序
        const int M = A.size(), N = B.size();
        int i = 0, j = 0;
        vector<Interval> ans;
        while (i < M && j < N) {
            // 如果A[i]和B[j]相交，[lo,hi]是相交区间
            int lo = max(A[i].start, B[j].start);
            int hi = min(A[i].end, B[j].end);
            if (lo <= hi) ans.push_back({lo, hi});
            
            if (A[i].end < B[j].end) i++;
            else j++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
