//
//  maximum-number-of-events-that-can-be-attended
//  https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int N = events.size();
        // 事件按开始时间排序
        sort(events.begin(), events.end());
        // 对进行中事件按结束时间升序排列
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0, i = 0, d = 0;
        while (!pq.empty() || i < N) {
            if (pq.empty()) d = events[i][0];
            // 把d前开始事件加入pq
            while (i < N && events[i][0] <= d) {
                pq.push(events[i][1]);
                i++;
            }
            // 把已结束事件移出pq
            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            // 选一个事件
            if (!pq.empty()) {
                pq.pop();
                d++;
                ans++;
            }
            
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
