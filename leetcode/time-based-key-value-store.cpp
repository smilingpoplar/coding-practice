//
//  time-based-key-value-store
//  https://leetcode.com/problems/time-based-key-value-store/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class TimeMap {
    unordered_map<string, map<int, string>> data; // key=>{timestamp,value}
    int timestamp = 0;
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        data[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto &mp = data[key];
        // 找<=timestamp时的值
        auto it = mp.upper_bound(timestamp);
        if (it == mp.begin()) return "";
        return prev(it)->second;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
