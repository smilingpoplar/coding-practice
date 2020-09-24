//
//  prison-cells-after-n-days
//  https://leetcode.com/problems/prison-cells-after-n-days/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // 用数组模拟会超时
        // 因为cells[0]==cells[7]==0，实际只有2^6=64种状态，N较大时会循环
        map<vector<int>, int> seen; // 用来判断循环
        int count = 0;
        while (!seen.count(cells) && N--) {
            seen[cells] = count++;
            cells = getNext(cells);
        }
        if (seen.count(cells)) {
            int cycleLen = count - seen[cells];
            N %= cycleLen;
            while (N--) {
                cells = getNext(cells);            
            }
        }
        return cells;
    }
    
    vector<int> getNext(vector<int> &cells) {
        vector<int> ans(8);
        for (int i = 1; i < 7; ++i) {
            ans[i] = (cells[i-1] == cells[i+1] ? 1 : 0);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
