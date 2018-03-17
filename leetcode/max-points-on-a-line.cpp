//
//  max-points-on-a-line
//  https://leetcode.com/problems/max-points-on-a-line/
//
//  Created by smilingpoplar on 15/6/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        const int N = points.size();
        int ans = 0;
        unordered_set<int> dups; // 重复出现的点
        // 每个点跟它后面的点比较，看相同斜率的有多少，斜率用最简分数表示
        for (int i = 0; i < N; i++) {
            if (dups.count(i)) continue;
            
            int sameICnt = 1; // 与第i点相同的多少个
            map<pair<int, int>, int> slopeICnt; // 过i点的那些斜率
            int maxSlopeICnt = 0; // 过i点的同斜率直线最多有几条
            for (int j = i + 1; j < N; j++) {
                auto &a = points[i], &b = points[j];
                if (a.x == b.x && a.y == b.y) {
                    dups.insert(j); // 记录重复的点，后面循环不再处理
                    ++sameICnt;
                    continue;
                }
                pair<int, int> slope = {0, 0}; // 不妨用{0,0}记垂直线的无效斜率
                if (a.x != b.x) {
                    int diffX = a.x - b.x, diffY = a.y - b.y;
                    int g = getGcd(diffX, diffY);
                    diffX /= g, diffY /= g;
                    slope = {diffX, diffY};
                }
                slopeICnt[slope]++;
                maxSlopeICnt = max(maxSlopeICnt, slopeICnt[slope]);
            }
            // 过i点同斜率的直线几条、就是除i外同直线的点有几个，再加上i点的个数，就是与i有关的同直线的点有几个
            ans = max(ans, maxSlopeICnt + sameICnt);
        }
        return ans;
    }
    
    int getGcd(int a, int b) {
        while (b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
