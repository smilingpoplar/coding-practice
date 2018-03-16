//
//  perfect-rectangle
//  https://leetcode.com/problems/perfect-rectangle/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // 满足两个条件：1.总矩形面积等于子矩形和  2.除了四顶点只出现1次，其他顶点出现偶数次
        int left = INT_MAX, bottom = INT_MAX, right = INT_MIN, top = INT_MIN;
        int sumArea = 0;
        set<pair<int, int>> st;
        for (auto &rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            left = min(left, x1);
            bottom = min(bottom, y1);
            right = max(right, x2);
            top = max(top, y2);
            
            sumArea += (x2 - x1) * (y2 - y1);
            
            pair<set<pair<int, int>>::iterator, bool> it;
            if (!(it = st.insert({x1, y1})).second) st.erase(it.first);
            if (!(it = st.insert({x1, y2})).second) st.erase(it.first);
            if (!(it = st.insert({x2, y1})).second) st.erase(it.first);
            if (!(it = st.insert({x2, y2})).second) st.erase(it.first);
        }

        return (right - left) * (top - bottom) == sumArea
            && st.size() == 4
            && st.count({left, bottom})
            && st.count({left, top})
            && st.count({right, bottom})
            && st.count({right, top});
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
