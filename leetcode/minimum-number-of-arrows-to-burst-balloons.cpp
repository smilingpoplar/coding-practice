//
//  minimum-number-of-arrows-to-burst-balloons
//  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 找最多的不重叠区间数
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int ans = 0;
        long end = LONG_MIN;
        for (auto &p : points) {
            if (p[0] > end) {
                end = p[1];
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
