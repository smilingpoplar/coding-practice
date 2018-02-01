//
//  minimum-number-of-arrows-to-burst-balloons
//  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        // 找最多的不重叠区间数
        sort(points.begin(), points.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });
        int ans = 0;
        long end = LONG_MIN;
        for (auto &p : points) {
            if (p.first > end) {
                ans++;
                end = p.second;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
