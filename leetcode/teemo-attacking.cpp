//
//  teemo-attacking
//  https://leetcode.com/problems/teemo-attacking/
//
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

/*
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int start = 0, end = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            if (timeSeries[i] > end) {
                ans += end - start;
                start = timeSeries[i], end = timeSeries[i] + duration;
            } else {
                end = max(end, timeSeries[i] + duration);
            }
        }
        ans += end - start;
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
