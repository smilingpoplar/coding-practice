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
    unordered_map<int, int> nums;
    int rows, cols, total;
public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = n_rows * n_cols;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        // 想象把矩阵二维索引转成一维索引放入数组nums[0..total)，初始nums[i]=i
        // 随机选择时，生成[0,total)间的随机idx，并选中nums[idx]（和数组尾nums[total-1]交换）
        // 用unordered_map模拟nums[]，考虑和数组尾交换这部分
        // 换到数组尾表示选中，而每次只从未选中选择，所以数组尾赋值nums[total-1]=nums[idx]不用写，
        // 只用写nums[idx]=nums[total-1]这部分
        int idx = rand() % total;
        total--;
        int num = getValue(idx);
        nums[idx] = getValue(total);
        return { num / cols, num % cols };
    }
    
    int getValue(int idx) {
        return nums.count(idx) ? nums[idx] : idx;
    }
    
    void reset() {
        nums.clear();
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
