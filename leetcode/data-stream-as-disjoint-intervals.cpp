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

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        // 合并所有与待插入区间curr重叠的区间
        Interval curr = { val, val };
        auto it = st.lower_bound({INT_MIN, val - 1}); // 最左的重叠区间右端是val-1
        while (it != st.end() && isOverlap(*it, curr)) {
            curr.start = min(curr.start, it->start);
            curr.end = max(curr.end, it->end);
            it = st.erase(it);
        }
        st.insert(curr);
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(st.begin(), st.end());
    }
private:
    struct Cmp {
        bool operator()(const Interval &a, const Interval &b) { return a.end < b.end; }
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
