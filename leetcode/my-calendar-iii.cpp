//
//  my-calendar-iii
//  https://leetcode.com/problems/my-calendar-iii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class MyCalendarThree {
    map<int, int> timeline;
public:
    MyCalendarThree() {      
    }
    
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int ans = 0;
        int ongoing = 0;
        for (auto &e : timeline) {
            ongoing += e.second;
            ans = max(ans, ongoing);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */

int main(int argc, const char * argv[]) {    
    return 0;
}