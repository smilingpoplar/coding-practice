//
//  meeting-rooms
//  https://leetcode.com/problems/meeting-rooms/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

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
    bool canAttendMeetings(vector<Interval>& intervals) {
        // 即要求区间不可重叠
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });
        int end = INT_MIN;
        for (auto &i : intervals) {
            if (i.start < end) return false;
            end = i.end;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
