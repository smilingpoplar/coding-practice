//
//  car-pooling
//  https://leetcode.com/problems/car-pooling/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 边界计数法
        map<int, int> timeline;
        for (auto &trip : trips) {
            timeline[trip[1]] += trip[0];
            timeline[trip[2]] -= trip[0];
        }
        int passengers = 0;
        for (auto &e : timeline) {
            passengers += e.second;
            if (passengers > capacity) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
