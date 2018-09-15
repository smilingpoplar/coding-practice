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
    unordered_map<int, int> mp; // 下标重映射
    int rows, cols, total;
public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = n_rows * n_cols;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        int idx = rand() % total;
        int theIdx = remapping(idx);
        total--;
        mp[idx] = remapping(total);
        return { theIdx / cols, theIdx % cols };
    }
    
    int remapping(int idx) {
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
