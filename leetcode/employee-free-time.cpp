//
//  employee-free-time
//  https://leetcode.com/problems/employee-free-time/
//
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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        // 边界计数法
        map<int, int> timeline;
        for (auto &employee : schedule) {
            for (auto &interval : employee) {
                timeline[interval.start]++;
                timeline[interval.end]--;
            }
        }

        vector<Interval> ans;
        int event = 0, start = -1;
        for (auto &e : timeline) {
            event += e.second;
            if (event <= 0) { // 空闲时间
                if (start == -1) {
                    start = e.first;
                }
            } else {
                if (start != -1) {
                    ans.push_back({ start, e.first });                    
                    start = -1;
                }
            }
        }       
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
