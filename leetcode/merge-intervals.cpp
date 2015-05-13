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
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> result;
        int index = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (i > 0 && intervals[i].start <= result[index - 1].end) {
                result[index - 1].start = min(result[index - 1].start, intervals[i].start);
                result[index - 1].end = max(result[index - 1].end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
                ++index;
            }
        }
        return result;
    }
private:
    static bool compare(const Interval &a, const Interval &b) {
        return a.start < b.start;
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
