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
        
        // 扫除线（sweep line）算法，把building离散化成(Li,Hi)和(Ri,Hi)两个端点，假想的垂直扫除线从左到右扫描，
        // 遇到左端点就把高度Hi加入某动态集合（这里用multiset），遇到右端点就把高度从集合中删除，
        // 在每个端点处看当前集合的最大高度currHi是否发生变化，若发生变化（currHi!=prevHi）说明出现了所需的跃变点
        
        // 先将所有端点按横坐标x排序，若x相同则：
        //   1.左端点排在右端点之前
        //   2.若都是左端点则按y从大到小排（避免currHi发生变化输出多余跃变点）
        //   3.若都是右端点则按y从小到大排（避免currHi发生变化输出多余跃变点）
        // 排序时，将左端点高度取负既可区分左右端点又可达到上述要求
        vector<pair<int, int>> endpoints; // (x,Hi)
        for (const auto &building : buildings) {
            endpoints.push_back({building[0], -building[2]});
            endpoints.push_back({building[1], building[2]});
        }
        sort(endpoints.begin(), endpoints.end());
        
        // 从左到右扫描
        vector<pair<int, int>> ans;
        multiset<int> set;
        int prevHi = 0;
        for (const auto &p : endpoints) {
            if (p.second < 0) set.insert(-p.second);
            else set.erase(set.find(p.second));
            int currHi = set.empty() ? 0 : *set.rbegin();
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
