//
//  lonely-pixel-i
//  https://leetcode.com/problems/lonely-pixel-i/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty()) return 0;
        const int R = picture.size(), C = picture[0].size();
        vector<int> rowCnt(R, 0), colCnt(C, 0);
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (picture[r][c] == 'B') {
                    rowCnt[r]++;
                    colCnt[c]++;
                }
            }
        }
        
        int ans = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (picture[r][c] == 'B' && rowCnt[r] == 1 && colCnt[c] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
