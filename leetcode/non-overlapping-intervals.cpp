//
//  non-overlapping-intervals
//  https://leetcode.com/problems/non-overlapping-intervals/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 等价问题：求最多的不重叠区间数
        sort(begin(intervals), end(intervals), [](const vector<int>& a, const vector<int>& b) { 
            return a[1] < b[1];
        });
        int end = INT_MIN, cnt = 0;
        for (auto &interval : intervals) {
            if (interval[0] >= end) { // 不重叠，取当前区间
                end = interval[1];
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
