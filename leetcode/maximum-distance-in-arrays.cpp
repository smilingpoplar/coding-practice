//
//  maximum-distance-in-arrays
//  https://leetcode.com/problems/maximum-distance-in-arrays/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // 最大距离来自：theMax-a[i][0]、a[i][n-1]-theMin
        int theMin = arrays[0][0], theMax = arrays[0][arrays[0].size() - 1];
        int ans = INT_MIN;
        for (int i = 1; i < arrays.size(); i++) {
            int newMin = arrays[i][0], newMax = arrays[i][arrays[i].size() - 1];
            ans = max(ans, max(theMax - newMin, newMax - theMin));
            theMin = min(theMin, newMin), theMax = max(theMax, newMax);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
