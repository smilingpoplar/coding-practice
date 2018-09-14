//
//  line-reflection
//  https://leetcode.com/problems/line-reflection/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        // 点可能有重叠，对称轴是(minX+maxX)/2
        // (x,y)关于对称轴的对称点是(minX+maxX-x, y)
        set<pair<int, int>> st; // 把点都塞到set中
        int minX = INT_MAX, maxX = INT_MIN;
        for (auto &p : points) {
            minX = min(minX, p.first);
            maxX = max(maxX, p.first);
            st.insert(p);
        }

        for (auto &p : points) {
            int reflX = minX + maxX - p.first;
            if (!st.count({reflX, p.second})) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
