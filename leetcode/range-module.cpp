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
        // 合并所有与待插入区间curr重叠的区间
        Interval curr = {left, right};
        auto it = st.lower_bound({INT_MIN, left}); // 最左的重叠区间的右端是left
        while (it != st.end() && isOverlap(*it, curr)) {
            curr.left = min(curr.left, it->left);
            curr.right = max(curr.right, it->right);
            it = st.erase(it);
        }
        st.insert(curr);
    }
    
    bool queryRange(int left, int right) {
        auto it = st.lower_bound({INT_MIN, left});
        return it != st.end() && it->left <= left && right <= it->right;            
    }
    
    void removeRange(int left, int right) {
        auto it = st.lower_bound({INT_MIN, left});
        Interval toRemove = {left, right};
        vector<Interval> toInsert;
        while (it != st.end() && isOverlap(*it, toRemove)) {
            if (it->left < toRemove.left) toInsert.push_back({it->left, toRemove.left});
            if (toRemove.right < it->right) toInsert.push_back({toRemove.right, it->right});
            it = st.erase(it);
        }
        st.insert(toInsert.begin(), toInsert.end());
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
