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
        // 区间互不重叠、已按起点排序 <=等价于=> 已按终点排序
        const int N = intervals.size();
        vector<Interval> ans;
        int idx = 0;
        while (idx < N && intervals[idx].end < newInterval.start) {
            ans.push_back(intervals[idx]);
            idx++;
        }
        // 至此 newInterval.start <= intervals[idx].end
        while (idx < N && intervals[idx].start <= newInterval.end) {
             // 重叠，合并到newInterval
            newInterval.start = min(newInterval.start, intervals[idx].start);
            newInterval.end = max(newInterval.end, intervals[idx].end);
            idx++;
        }
        ans.push_back(newInterval);
        // 至此 newInterval.end < intervals[idx].start
        while (idx < N) {
            ans.push_back(intervals[idx]);
            idx++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<Interval> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    Interval newInterval = {4,9};
    Solution solution;
    auto ans = solution.insert(intervals, newInterval);
    for (const auto &interval : ans) {
        cout << interval.start << "," << interval.end << " ";
    }
    
    return 0;
}
