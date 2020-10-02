//
//  the-skyline-problem
//  https://leetcode.com/problems/the-skyline-problem/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 扫描线算法，垂直线向右扫，遇到左端点把高度Hi加入集合，遇到右端点把Hi移出集合。
        // 若集合中最大高度变化（currHi!=prevHi），就得所需的跃变点。
        // 当x相同时，为避免currHi变化输出多余跃变点，左端点再按h从大到小排，右端点再按h从小到大排。
        // 不妨将左端点的高度取负值，然后统一排序。这样既区分了左右端点，又满足排序要求。
        vector<array<int,2>> points; // (x,h)
        for (auto &b : buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        sort(points.begin(), points.end());
        
        vector<vector<int>> ans;
        multiset<int> st;
        int prevHi = 0;
        for (auto& [x, h] : points) { // 遍历points相当于垂直线向右扫
            if (h < 0) st.insert(-h); // 左端点
            else st.erase(st.find(h)); // 右端点

            int currHi = st.empty() ? 0 : *st.rbegin();
            if (currHi != prevHi) {
                ans.push_back({ x, currHi });
                prevHi = currHi;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> buildings = {
        {2, 9, 10},
        {3, 7, 15},
        {5, 12, 12},
        {15, 20, 10},
        {19, 24, 8},
    };
    Solution solution;
    auto result = solution.getSkyline(buildings);
    for (const auto &point : result) {
        cout << point.first << " " << point.second << endl;
    }
    
    return 0;
}
