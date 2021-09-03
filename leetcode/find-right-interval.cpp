//
//  find-right-interval
//  https://leetcode.com/problems/find-right-interval/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp; // start=>idx
        for (int i = 0; i < intervals.size(); i++) {
            mp[intervals[i][0]] = i;
        }

        vector<int> ans;
        // 每个区间找>=end的下一起点：mp.lower_bound(end)
        for (auto &interval : intervals) {
            auto it = mp.lower_bound(interval[1]);
            ans.push_back(it != mp.end() ? it->second : -1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
