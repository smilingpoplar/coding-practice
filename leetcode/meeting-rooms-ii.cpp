//
//  meeting-rooms-ii
//  https://leetcode.com/problems/meeting-rooms-ii/
//
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
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // 边界计数法
        map<int, int> mp;
        for (auto & interval : intervals) {
            mp[interval.start]++;
            mp[interval.end]--;
        }
        // 遍历mp，累加进行中的事件数
        int rooms = 0, ans = 0;
        for (auto &e : mp) {
            rooms += e.second;
            ans = max(ans, rooms);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
