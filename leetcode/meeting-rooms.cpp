//
//  meeting-rooms
//  https://leetcode.com/problems/meeting-rooms/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        // 题目：是否所有区间都不重叠？
        sort(begin(intervals), end(intervals), [](const Interval &a, const Interval &b) {
            return a.end < b.end;
        });
        int end = INT_MIN;
        for (auto& interval : intervals) {
            if (interval.start < end) return false;
            end = interval.end;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
