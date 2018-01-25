//
//  insert-interval
//  https://leetcode.com/problems/insert-interval/
//
//  Created by smilingpoplar on 15/5/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (inserted || intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
            } else if (newInterval.end < intervals[i].start) {
                result.push_back(newInterval);
                inserted = true;
                result.push_back(intervals[i]);
            } else { // merge
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if (!inserted) result.push_back(newInterval);
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<Interval> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    Interval newInterval = {4,9};
    Solution solution;
    auto result = solution.insert(intervals, newInterval);
    for (const auto &interval : result) {
        cout << interval.start << "," << interval.end << " ";
    }
    
    return 0;
}
