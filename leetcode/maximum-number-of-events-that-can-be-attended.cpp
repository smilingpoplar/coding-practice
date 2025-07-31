//
//  maximum-number-of-events-that-can-be-attended
//  https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int N = events.size();
        // 事件按开始时间升序
        sort(events.begin(), events.end());
        // 尽量选结束时间早的，"进行中事件"的结束时间升序
        priority_queue<int, vector<int>, greater<>> pq;

        int maxDay = 0;
        for (auto& e : events) {
            maxDay = max(maxDay, e[1]);
        }
        int ans = 0;
        for (int day = 1, i = 0; day <= maxDay; day++) {  // 扫描线
            // 当天或之前开始的事件，结束时间入堆
            while (i < N && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }
            // 移除已结束的事件
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // 取结束时间最早的
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};