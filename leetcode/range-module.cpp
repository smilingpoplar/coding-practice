//
//  range-module
//  https://leetcode.com/problems/range-module/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class RangeModule {
    struct Interval {
        int left;
        int right;
    };
    struct Cmp {
        bool operator()(const Interval &a, const Interval &b) {
            return a.right < b.right;
        }
    };
    set<Interval, Cmp> st;
    
    bool isOverlap(const Interval &a, const Interval &b) {
        return a.left <= b.right && b.left <= a.right;
    }
public:
    RangeModule() { 
    }
    
    void addRange(int left, int right) {
        // 首个与{left, right}重叠的区间满足：toFind.right>=left
        auto it = st.lower_bound({INT_MIN, left});
        Interval toInsert = {left, right};
        while (it != st.end() && isOverlap(*it, toInsert)) {
            toInsert.left = min(toInsert.left, it->left);
            toInsert.right = max(toInsert.right, it->right);
            it = st.erase(it);
        }
        st.insert(toInsert);
    }
    
    bool queryRange(int left, int right) {
        auto it = st.lower_bound({INT_MIN, left});
        return it != st.end() && it->left <= left && right <= it->right;            
    }
    
    void removeRange(int left, int right) {
        auto it = st.lower_bound({INT_MIN, left});
        Interval toRemove = {left, right};
        vector<Interval> afterRemove;
        while (it != st.end() && isOverlap(*it, toRemove)) {
            if (it->left < toRemove.left) afterRemove.push_back({it->left, toRemove.left});
            if (toRemove.right < it->right) afterRemove.push_back({toRemove.right, it->right});
            it = st.erase(it);
        }
        st.insert(afterRemove.begin(), afterRemove.end());
    }
};

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
