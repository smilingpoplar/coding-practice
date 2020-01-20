//
//  rectangle-area-ii
//  https://leetcode.com/problems/rectangle-area-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        // 扫描线算法：
        // 水平扫描线向上扫，每遇到y边界都累加一横块面积。
        // 面积高为 (y边界-前一y边界)，面积长为 旧区间集合的重叠长。

        // 要水平线向上扫，所以先按y坐标排序
        const int LOWER = 0, UPPER = 1;
        vector<vector<int>> events;
        for (auto &rect : rectangles) {
            events.push_back({rect[1], LOWER, rect[0], rect[2]});
            events.push_back({rect[3], UPPER, rect[0], rect[2]});
        }
        sort(events.begin(), events.end());

        // 遇到下边界把横坐标区间[x1,x2]加入集合，
        // 遇到上边界把[x1,x2]移出集合。
        const int MOD = 1e9 + 7;
        multiset<vector<int>> st; // st{ [x1,x2] }
        int preY = INT_MIN;
        int ans = 0;
        for (auto &e : events) {
            int y = e[0], type = e[1], x1 = e[2], x2 = e[3];
            if (preY != INT_MIN) {
                int height = y - preY;
                int width = getWidth(st);
                ans = (ans + (long)width * height) % MOD;
            }
            
            if (type == LOWER) st.insert({x1, x2});
            else st.erase(st.find({x1, x2}));
            preY = y;
        }
        return ans;
    }
    
    // 区间集合的重叠长
    int getWidth(multiset<vector<int>> &st) {
        int ans = 0;
        int curr = INT_MIN;
        for (auto &x : st) {
            curr = max(curr, x[0]);
            ans += max(x[1] - curr, 0);
            curr = max(curr, x[1]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
