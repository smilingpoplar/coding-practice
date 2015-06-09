//
//  max-points-on-a-line
//  https://leetcode.com/problems/max-points-on-a-line/
//
//  Created by smilingpoplar on 15/6/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        const int N = (int)points.size();
        
        int maxPoints = 0;
        unordered_set<int> dupIndices;
        for (int i = 0; i < N; ++i) {
            if (dupIndices.find(i) != dupIndices.end()) continue;
            
            int sameCountI = 1; // 第i点有几个相同的点
            unordered_map<double, int> slopeCountI; // 经过第i点的那些斜率
            int maxSlopeCountI = 0; // 经过第i点的同斜率直线最多有几条
            for (int j = i + 1; j < N; ++j) {
                const Point &a = points[i];
                const Point &b = points[j];
                
                if (a.x == b.x && a.y == b.y) {
                    dupIndices.insert(j);
                    ++sameCountI;
                } else {
                    double slope = (a.x == b.x) ? numeric_limits<double>::infinity() : double(a.y - b.y) / (a.x - b.x);
                    ++slopeCountI[slope];
                    maxSlopeCountI = max(maxSlopeCountI, slopeCountI[slope]);
                }
            }
            maxPoints = max(maxPoints, maxSlopeCountI + sameCountI);
        }
        
        return maxPoints;
    }
};

int main(int argc, const char * argv[]) {
    vector<Point> points = { {0,0}, {-1,-1}, {2,2} };
    Solution solution;
    cout << solution.maxPoints(points);

    return 0;
}
