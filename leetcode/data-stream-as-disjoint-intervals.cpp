//
//  data-stream-as-disjoint-intervals
//  https://leetcode.com/problems/data-stream-as-disjoint-intervals/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class SummaryRanges {
    map<int, int> _ranges; // left=>right, [left,right]
    using RI = map<int, int>::iterator;
    array<RI, 2> getOverlapRanges(int val) {
        auto l = _ranges.upper_bound(val - 1);
        if (l != begin(_ranges) && prev(l)->second >= val - 1) l = prev(l);
        auto r = _ranges.upper_bound(val + 1);
        return {l, r};
    }
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        auto [l, r] = getOverlapRanges(val);
        int left = val, right = val;
        if (l != r) {
            left = min(val, l->first);
            right = max(val, prev(r)->second);
            _ranges.erase(l, r);
        }
        _ranges[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto& [left, right] : _ranges) {
            ans.push_back({left, right});
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
