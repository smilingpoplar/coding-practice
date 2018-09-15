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
        if (timeSeries.empty()) return 0;
        int ans = 0;
        for (int i = 1; i < timeSeries.size(); i++) {
            ans += min(duration, timeSeries[i] - timeSeries[i-1]);
        }
        ans += duration;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
