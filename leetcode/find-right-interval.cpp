//
//  find-right-interval
//  https://leetcode.com/problems/find-right-interval/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

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
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> m; // start=>idx
        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i].start] = i;
        }

        vector<int> ans;
        // 每个区间使用startMap.lower_bound(end)找>=end的下一起点
        for (auto &interval : intervals) {
            auto it = m.lower_bound(interval.end);
            if (it != m.end()) {
                ans.push_back(it->second);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
