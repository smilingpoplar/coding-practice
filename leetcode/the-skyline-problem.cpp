//
//  the-skyline-problem
//  https://leetcode.com/problems/the-skyline-problem/
//
//  Created by smilingpoplar on 15/6/16.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // 参考：http://www.cnblogs.com/grandyang/p/4534586.html
        
        // 扫除线（sweep line）算法，把building离散化成(Li,-Hi)和(Ri,Hi)两个点，把所有点加入points[]并排序。
        // 假想有垂直扫除线从左到右扫描，遇到左端点（高度取负值）就把高度Hi加入集合，遇到右端点就把高度Hi从集合中删除，
        // 扫描*看集合中的最大高度*currHi是否发生变化，若发生变化（currHi!=prevHi）说明出现了所需的跃变点。
        
        // 为什么左端点高度取负值？为避免currHi发生变化输出多余跃变点，当x相同时：
        //   1. 左端点排在右端点之前
        //   2. 都是左端点则按y从大到小排
        //   3. 都是右端点则按y从小到大排
        // *将左端点高度取负值*既可区分左右端点又可达到上述要求。
        vector<pair<int, int>> points; // (x,h)
        for (auto &building : buildings) {
            points.push_back({building[0], -building[2]});
            points.push_back({building[1], building[2]});
        }
        sort(points.begin(), points.end());
        
        // 从左到右扫描
        vector<pair<int, int>> ans;
        multiset<int> st;
        int prevHi = 0;
        for (auto &p : points) {
            if (p.second < 0) st.insert(-p.second); // 左端点
            else st.erase(st.find(p.second)); // 右端点
            int currHi = st.empty() ? 0 : *st.rbegin();
            if (currHi != prevHi) {
                ans.push_back({ p.first, currHi });
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
