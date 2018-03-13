//
//  meeting-rooms-ii
//  https://leetcode.com/problems/meeting-rooms-ii/
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
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // 边界计数法
        map<int, int> mp; // 起点+1，终点-1
        for (auto & interval : intervals) {
            mp[interval.start]++;
            mp[interval.end]--;
        }
        // 想像有根时间线扫过各个时间，累加进行中的事件数
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
