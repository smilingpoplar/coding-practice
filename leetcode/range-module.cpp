//
//  range-module
//  https://leetcode.com/problems/range-module/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class RangeModule {
    map<int, int> _ranges; // left=>right, [left,right)
    using RI = map<int, int>::iterator;
    array<RI, 2> getOverlapRanges(int left, int right) {
        // 左闭右开，左边找第一个相交的区间
        auto l = _ranges.upper_bound(left); // toFind.left>left
        if (l != begin(_ranges) && prev(l)->second >= left) // toFind.left<=left&&toFind.right>=left
            l = prev(l);
        // 右边找第一个不相交的区间
        auto r = _ranges.upper_bound(right); // toFind.left>right
        return {l, r};
    }
public:
    RangeModule() { 
    }
    
    void addRange(int left, int right) {
        auto [l, r] = getOverlapRanges(left, right);
        if (l != r) {
            left = min(left, l->first);
            right = max(right, prev(r)->second);
            _ranges.erase(l, r);
        }
        _ranges[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto [l, r] = getOverlapRanges(left, right);
        return l != r && l->first <= left && right <= l->second;
    }
    
    void removeRange(int left, int right) {
        auto [l, r] = getOverlapRanges(left, right);
        if (l != r) {
            int start = min(left, l->first);
            int end = max(right, prev(r)->second);
            _ranges.erase(l, r);
            if (start < left) _ranges[start] = left;
            if (right < end) _ranges[right] = end;
        }
    }
};

/*
class RangeModule {
    struct Interval { // [left,right)
        int left;
        int right;
    };
    struct Cmp {
        bool operator()(const Interval &a, const Interval &b) const {
            return a.right < b.right;
        }
    };
    set<Interval, Cmp> st;
    
    // 认为[x,y)和[y,z)重叠，以合并区间
    bool isOverlap(const Interval &a, const Interval &b) {
        return a.left <= b.right && b.left <= a.right;
    }
public:
    RangeModule() { 
    }
    
    void addRange(int left, int right) {
        // 首个与[left,right)重叠的区间满足：toFind.right>=left
        auto it = st.lower_bound({INT_MIN, left});
        Interval adding({left, right});
        while (it != st.end() && isOverlap(*it, adding)) {
            adding.left = min(adding.left, it->left);
            adding.right = max(adding.right, it->right);
            it = st.erase(it);
        }
        st.insert(adding);
    }
    
    bool queryRange(int left, int right) {
        auto it = st.lower_bound({INT_MIN, left});
        return it != st.end() && it->left <= left && right <= it->right;            
    }
    
    void removeRange(int left, int right) {
        auto it = st.lower_bound({INT_MIN, left});
        Interval removing({left, right});
        vector<Interval> remain;
        while (it != st.end() && isOverlap(*it, removing)) {
            if (it->left < removing.left) 
                remain.push_back({it->left, removing.left});
            if (removing.right < it->right) 
                remain.push_back({removing.right, it->right});
            it = st.erase(it);
        }
        st.insert(remain.begin(), remain.end());
    }
};
*/

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
