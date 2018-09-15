//
//  random-flip-matrix
//  https://leetcode.com/problems/random-flip-matrix/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    unordered_map<int, int> mp; // rnd=>idx
    int rows, cols, total;
public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = n_rows * n_cols;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        // 想象把矩阵二维索引转成一维索引放入数组mp[0..total)，初始mp[i]=i
        // 每次生成[0,total)的随机数rnd，rnd处的索引被选中移到数组尾，total-1处的索引被移到rnd处
        // 用unordered_map模拟数组
        int rnd = rand() % total;
        total--;
        int idx = getIdx(rnd);
        mp[rnd] = getIdx(total);
        mp[total] = idx;
        return { idx / cols, idx % cols };
    }
    
    int getIdx(int rnd) {
        return mp.count(rnd) ? mp[rnd] : rnd;
    }
    
    void reset() {
        mp.clear();
        total = rows * cols;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
