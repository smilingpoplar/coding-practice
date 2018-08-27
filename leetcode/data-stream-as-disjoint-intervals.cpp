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
        // 首个与{val,val}重叠区间toFind.end>=val-1
        auto it = st.lower_bound({INT_MIN, val - 1}); 
        Interval toInsert = { val, val };
        while (it != st.end() && isOverlap(*it, toInsert)) {
            toInsert.start = min(toInsert.start, it->start);
            toInsert.end = max(toInsert.end, it->end);
            it = st.erase(it);
        }
        st.insert(toInsert);
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
