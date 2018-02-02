//
//  merge-intervals
//  https://leetcode.com/problems/merge-intervals/
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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        // 根据起点排序，避免了合并会修改前面区间起点的问题。起点相同时，不妨先取范围大的。
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start || (a.start == b.start && a.end > b.end);
        });
        
        vector<Interval> ans;
        auto last = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > last.end) {
                ans.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        }
        ans.push_back(last);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<Interval> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution solution;
    auto result = solution.merge(intervals);
    for (const auto &interval : result) {
        cout << interval.start << "," << interval.end << " ";
    }
    
    return 0;
}