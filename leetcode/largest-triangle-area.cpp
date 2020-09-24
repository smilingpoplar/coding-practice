//
//  largest-triangle-area
//  https://leetcode.com/problems/largest-triangle-area/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const int N = points.size();
        double ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    ans = max(ans, area(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
    
    double area(const vector<int> &x, const vector<int> &y, const vector<int> &z) {
        // x、y、z三点可以构造x->y向量a、y->z向量b，计算a、b的叉积
        // 根据平行四边形面积=abs(叉积)，三角形面积=abs(叉积)*0.5
        vector<int> a = { y[0]-x[0], y[1]-x[1] };
        vector<int> b = { z[0]-y[0], z[1]-y[1] };
        int crossProd = a[0] * b[1] - a[1] * b[0];
        return abs(crossProd) * 0.5;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
