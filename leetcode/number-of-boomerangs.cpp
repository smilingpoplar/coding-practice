//
//  number-of-boomerangs
//  https://leetcode.com/problems/number-of-boomerangs/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            // 以points[i]作为回旋镖的中点
            unordered_map<int, int> group; // dist=>count
            for (int j = 0; j < points.size(); j++) {
                if (j == i) continue;
                group[dist(points[i], points[j])]++; // 与i同距离的有哪些组
            }
            for (auto &g : group) {
                ans += g.second * (g.second - 1); // 组内任选两个
            }
        }
        return ans;
    }
    
    int dist(pair<int, int> &a, pair<int, int> &b) {
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        return dx * dx + dy * dy;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
