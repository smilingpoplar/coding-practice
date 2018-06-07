//
//  convex-polygon
//  https://leetcode.com/problems/convex-polygon/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        const int N = points.size();
        if (N < 3) return false;
        
        int prev = 0;
        for (int i = 0; i < N; i++) {
            int curr = getDirection(points[i], points[(i+1) % N], points[(i+2) % N]);
            if (curr == 0) continue;
            if (prev == 0) prev = curr;
            else if (curr != prev) return false;
        }
        return true;
    }
    
    int getDirection(const vector<int> &x, const vector<int> &y, const vector<int> &z) {
        // x、y、z三点构成a、b两向量，计算a、b的叉积，返回1、-1、0表示拐向
        vector<int> a = { y[0] - x[0], y[1] - x[1] };
        vector<int> b = { z[0] - y[0], z[1] - y[1] };
        int crossProd = a[0] * b[1] - a[1] * b[0];
        return crossProd > 0 ? 1 : (crossProd < 0 ? -1 : 0);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
