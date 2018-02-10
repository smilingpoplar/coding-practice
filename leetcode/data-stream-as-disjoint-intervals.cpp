//
//  data-stream-as-disjoint-intervals
//  https://leetcode.com/problems/data-stream-as-disjoint-intervals/
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

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        Interval curr = { val, val };
        // 待插入区间[start,end]看与前后区间是否重叠，重叠就更新待插入区间、并删掉重叠的
        auto it = st.lower_bound(curr);
        if (it != st.begin() && isOverlap(*prev(it), curr)) --it;
        while (it != st.end() && isOverlap(*it, curr)) {
            curr.start = min(curr.start, it->start);
            curr.end = max(curr.end, it->end);
            it = st.erase(it);
        }
        st.insert(it, curr);
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(st.begin(), st.end());
    }
private:
    struct Cmp {
        bool operator()(const Interval &a, const Interval &b) { return a.start < b.start; }
    };
    set<Interval, Cmp> st;

    bool isOverlap(const Interval &a, const Interval &b) {
        return (a.start <= b.end + 1) && (b.start <= a.end + 1);
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
