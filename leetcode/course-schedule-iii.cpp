//
//  course-schedule-iii
//  https://leetcode.com/problems/course-schedule-iii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        priority_queue<int> taken; // 已选课程的持续时间t

        int end = 0; // 已选课程的实际结束时间
        for (auto &c : courses) {
            if (end + c[0] <= c[1]) { // 选课程c
                taken.push(c[0]);
                end += c[0];
            } else if (!taken.empty()) { // 替换掉持续时间t最大且更大的已选课程
                int t = taken.top();
                if (t > c[0]) {
                    taken.pop();
                    taken.push(c[0]);
                    end += c[0] - t;
                }
            }
        }
        return taken.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
