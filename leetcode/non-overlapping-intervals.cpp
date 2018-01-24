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
    // 等同求最多不重叠区间的方法
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) { 
            return a.end < b.end;
        });
        int count = 0;
        int end = INT_MIN;
        for (const auto &interval : intervals) {
            if (interval.start >= end) { // 不重叠，取当前区间
                end = interval.end;
            } else {
                ++count;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
