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
        // 要找符合条件的黑点位置：
        // 1. 该行有N个黑点
        // 2. 该列有N个黑点
        // 3. 该黑点所在行刚好有N个相同行
        if (picture.empty()) return 0;
        const int R = picture.size(), C = picture[0].size();

        unordered_map<string, int> mp; // row=>count，统计相同行
        vector<int> colCnt(C, 0); // 各列有几个黑点
        for (int r = 0; r < R; r++) {
            string row;
            int blackCnt = 0; // 该行有几个黑点
            for (int c = 0; c < C; c++) {
                row += picture[r][c];
                if (picture[r][c] == 'B') {
                    blackCnt++;
                    colCnt[c]++;
                }
            }
            if (blackCnt != N) continue; // 规则1
            mp[row]++;
        }

        int ans = 0;
        for (auto &e : mp) {
            if (e.second != N) continue; // 规则3
            auto &row = e.first;
            for (int c = 0; c < C; c++) {
                if (row[c] == 'B' && colCnt[c] == N) // 规则2
                    ans += N;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
