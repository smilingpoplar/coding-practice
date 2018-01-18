//
//  course-schedule-iii
//  https://leetcode.com/problems/course-schedule-iii/
//
//  Created by smilingpoplar on 17/12/02.
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
        priority_queue<int> taken; // 已选的课程，这里只记录duration
        
        int current = 0;
        for (const auto &c : courses) {
            if (current + c[0] <= c[1]) { // 选课程c
                taken.push(c[0]);
                current += c[0];
            } else if (!taken.empty()) { // 替换一个持续时间更大的已选课程，选其中最大的
                int t = taken.top();
                if (t > c[0]) {
                    taken.pop();
                    taken.push(c[0]);
                    current += c[0] - t;
                }
            }
        }
        return taken.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}