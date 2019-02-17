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
        // 水平扫描线向上扫，遇到下边界把区间[x1,x2]加入集合，遇到上边界把区间[x1,x2]移出集合。
        // 每次遇到边界要先计算，面积 += 集合中所有区间贡献的重叠长 * (边界-前一边界)贡献的高。
        const int OPEN = 0, CLOSE = 1;
        vector<vector<int>> events;
        for (auto &rect : rectangles) {
            events.push_back({rect[1], OPEN, rect[0], rect[2]});
            events.push_back({rect[3], CLOSE, rect[0], rect[2]});
        }
        sort(events.begin(), events.end());

        const int MOD = 1e9 + 7;
        // {x1,x2}的集合，按照左端点排序
        multiset<vector<int>> st;
        int preY = INT_MIN;
        int ans = 0;
        for (auto &e : events) {
            int y = e[0], type = e[1], x1 = e[2], x2 = e[3];
            // 计算面积
            if (preY != INT_MIN) {
                int width = intervalsLen(st);
                long height = y - preY;
                ans = (ans + width * height) % MOD;
            }
            
            if (type == OPEN) st.insert({x1, x2});
            else st.erase(st.find({x1, x2}));
            preY = y;
        }
        return ans;
    }
    
    // 集合中所有区间贡献的重叠长
    int intervalsLen(multiset<vector<int>> &st) {
        int ans = 0;
        int curr = INT_MIN;
        for (auto &x : st) {
            curr = max(curr, x[0]);
            ans += max(x[1] - curr, 0);
            curr = max(curr, x[1]);
        }
        return ans;
    }

    /*
    int intervalsLen(multiset<vector<int>> &st) {
        int ans = 0;
        int start = 0, end = 0; // [start,end)是上个待合并区间
        for (auto &x : st) {
            if (x[0] >= end) { // 新区间
                ans += end - start;
                start = x[0];
            }
            end = x[1];
        }
        ans += end - start;
        return ans;
    }
    */
};

int main(int argc, const char * argv[]) {
    return 0;
}
