//
//  teemo-attacking
//  https://leetcode.com/problems/teemo-attacking/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // 前闭后开区间 [time, time+duration)
        int ans = 0;
        int start = 0, end = 0;
        for (int time : timeSeries) {
            if (time >= end) { // 新区间
                ans += end - start;
                start = time;
            }
            end = time + duration;
        }
        ans += end - start;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
