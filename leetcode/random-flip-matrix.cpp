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
    // 把2d矩阵当作1d数组处理
    unordered_map<int, int> mp; // 已用过下标=>未用过下标
    int rows, cols, total;
public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = rows * cols;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        int r = rand() % total--;
        int rr = mapping(r);    // r对应到未用过下标rr
        mp[r] = mapping(total); // rr要被使用，让r重映射到未用过的下标
        return { rr / cols, rr % cols };
    }
    
    int mapping(int idx) {
        return mp.count(idx) ? mp[idx] : idx;
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
