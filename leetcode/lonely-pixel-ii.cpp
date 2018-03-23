//
//  lonely-pixel-ii
//  https://leetcode.com/problems/lonely-pixel-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        // 题目说，要找符合条件的黑点位置
        // rule1：该行要有N个黑点、该列要有N个黑点
        // rule2：该黑点所在行的相同行要有N个
        if (picture.empty()) return 0;
        const int R = picture.size();
        const int C = picture[0].size();

        // 先从rule2入手，统计相同行
        unordered_map<string, int> mp; // row=>count
        // 顺带为统计各列有几个黑点
        vector<int> rowCnt(R, 0), colCnt(C, 0);
        for (int r = 0; r < R; r++) {
            string row;
            int blackCnt = 0; // 顺带统计各行有几个黑点
            for (int c = 0; c < C; c++) {
                row += picture[r][c];
                if (picture[r][c] == 'B') {
                    blackCnt++;
                    colCnt[c]++;
                }
            }
            if (blackCnt != N) continue;
            mp[row]++;
        }
        // 检查符合rule2的行里各黑点
        int ans = 0;
        for (auto &e : mp) {
            if (e.second != N) continue;
            auto &row = e.first;
            for (int c = 0; c < row.size(); c++) {
                if (row[c] == 'B' && colCnt[c] == N) // N行同一列的黑点都满足
                    ans += N;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
