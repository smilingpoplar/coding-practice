//
//  minimum-time-visiting-all-points
//  https://leetcode.com/problems/minimum-time-visiting-all-points/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // 贪心，尽量走斜线，剩余再走横竖线
        const int N = points.size();
        int ans = 0;
        for (int i = 1; i < N; i++) {
            auto &cur = points[i], &pre = points[i-1];
            int diffX = abs(cur[0] - pre[0]), diffY = abs(cur[1] - pre[1]);
            ans += max(diffX, diffY);
        }        
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
