//
//  my-calendar-i
//  https://leetcode.com/problems/my-calendar-i/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class MyCalendar {
    map<int, int> mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(start); // 起点>=start后的第一个区间
        if (it != mp.end()) {
            if (end > it->first) return false;
        }
        if (it != mp.begin()) {
            --it;
            if (start < it->second) return false;
        }
        mp[start] = end;
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
