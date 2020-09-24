//
//  my-calendar-i
//  https://leetcode.com/problems/my-calendar-i/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class MyCalendar {
    map<int, int> timeline;
public:
    MyCalendar() { 
    }
    
    bool book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int ongoing = 0;
        for (auto &e : timeline) {
            ongoing += e.second;
            if (ongoing >= 2) {
                timeline[start]--;
                timeline[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

int main(int argc, const char * argv[]) {    
    return 0;
}
