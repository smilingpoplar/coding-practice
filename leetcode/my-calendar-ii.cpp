//
//  my-calendar-ii
//  https://leetcode.com/problems/my-calendar-ii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class MyCalendarTwo {
    map<int, int> timeline;
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int ongoing = 0;
        for (auto &e : timeline) {
            ongoing += e.second;
            if (ongoing >= 3) {
                timeline[start]--;
                timeline[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

int main(int argc, const char * argv[]) {    
    return 0;
}
