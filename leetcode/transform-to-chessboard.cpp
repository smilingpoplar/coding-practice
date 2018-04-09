//
//  transform-to-chessboard
//  https://leetcode.com/problems/transform-to-chessboard/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        // 1. 合法棋盘只有两种行、且01相反，只能有两种列、且01相反
        // 2. 每行或每列01的个数相等或差1
        const int N = board.size();
        vector<int> rows(N, 0), cols(N, 0);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r][c] == 1) {
                    rows[r] |= 1 << c;
                    cols[c] |= 1 << r;
                }
            }
        }
        
        int swap1 = swapLines(rows);
        if (swap1 == -1) return -1;
        int swap2 = swapLines(cols);
        if (swap2 == -1) return -1;
        return swap1 + swap2;
    }
    
    int swapLines(vector<int> &lines) {
        const int N = lines.size();
        const int mask = (1 << N) - 1;
        // 检查条件1 
        set<int> st(lines.begin(), lines.end());
        if (st.size() != 2) return -1;
        vector<int> l(st.begin(), st.end());
        if ((l[0] ^ l[1]) != mask) return -1;
        // 检查条件2
        int ones = countOnes(l[0]), zeros = N - ones;
        if (ones != zeros && abs(ones - zeros) != 1) return -1;
        // 计算需要的swap数
        const int mask1 = 0x55555555 & mask, mask2 = 0xaaaaaaaa & mask;
        int ans = INT_MAX;
        if (ones == zeros || ones > zeros)
            ans = min(ans, countOnes(l[0] ^ mask1) / 2);
        if (ones == zeros || ones < zeros)
            ans = min(ans, countOnes(l[0] ^ mask2) / 2);
        return ans;
    }
    
    int countOnes(int n) {
        int ans = 0;
        while (n) {
            n &= n - 1 ;
            ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
