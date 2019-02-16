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
        // 合法棋盘只有两种行，且01相反、01个数相等或差1；
        //              列，...
        const int N = board.size();
        vector<int> rows(N, 0), cols(N, 0);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r][c] == 1) {
                    rows[r] |= 1 << c; // 行r变成二进制数
                    cols[c] |= 1 << r;
                }
            }
        }
        
        int swap1 = minSwaps(rows);
        if (swap1 == -1) return -1;
        int swap2 = minSwaps(cols);
        if (swap2 == -1) return -1;
        return swap1 + swap2;
    }
    
    int minSwaps(vector<int> &lines) {
        const int N = lines.size();
        set<int> st(lines.begin(), lines.end());
        if (st.size() != 2) return -1; // 只有两种行
        vector<int> l(st.begin(), st.end());
        if ((l[0] & l[1]) != 0) return -1; // 且01相反
        int ones = count1s(l[0]), zeros = N - ones;
        if (abs(ones - zeros) > 1) return -1; // 01个数相等或差1
        // 往mask1或mask2靠，最少需要多少swap
        const int mask = (1 << N) - 1; // 后N位全是1
        const int mask1 = 0x55555555 & mask, mask2 = 0xaaaaaaaa & mask;
        int ans = INT_MAX;
        if (ones >= zeros) ans = min(ans, count1s(l[0] ^ mask1) / 2); // 往mask1靠
        if (ones <= zeros) ans = min(ans, count1s(l[0] ^ mask2) / 2); // 往mask2靠
        return ans;
    }
    
    int count1s(int n) {
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
