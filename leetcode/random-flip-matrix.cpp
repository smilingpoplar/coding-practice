//
//  random-flip-matrix
//  https://leetcode.com/problems/random-flip-matrix/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 把2d矩阵当作1d数组处理
    // Fisher-Yates洗牌：生成0~n-1随机数r，交换r和n-1，n--
    unordered_map<int, int> mp; // 记录r和n-1的交换操作
    int rows, cols, n;
public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        n = rows * cols;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        int r = rand() % n;
        int tmp = mapping(r);
        mp[r] = mapping(n-1);
        mp[n-1] = tmp;
        n--;
        return { tmp / cols, tmp % cols };
    }
    
    int mapping(int idx) {
        return mp.count(idx) ? mp[idx] : idx;
    }
    
    void reset() {
        mp.clear();
        n = rows * cols;
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
