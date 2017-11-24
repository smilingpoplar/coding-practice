//
//  non-overlapping-intervals
//  https://leetcode.com/problems/non-overlapping-intervals/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // 转变成找不重叠区间的最大数，贪婪法，先取早结束的区间
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](const Interval &a, const Interval &b) { return a.end < b.end; });
        const int N = intervals.size();
        int nonOverlap = 0;
        int end = INT_MIN;
        for (const auto &interval : intervals) {
            if (interval.start >= end) { // 不重叠
                nonOverlap++;
                end = interval.end;
            }
        }
        return N - nonOverlap;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
