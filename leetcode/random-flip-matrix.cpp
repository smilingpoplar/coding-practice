//
//  random-flip-matrix
//  https://leetcode.com/problems/random-flip-matrix/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 把2D矩阵当作1D数组处理
    // Fisher-Yates洗牌：生成[0,n-1]随机数r，交换r和n-1，n--
    unordered_map<int, int> mapping; // 记录r和n-1的交换操作
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
        // 交换r和n-1索引在mapping中的值
        int tmp = getMapping(r);
        mapping[r] = getMapping(n-1);
        mapping[n-1] = tmp;
        n--;
        return { tmp / cols, tmp % cols };
    }
    
    int getMapping(int idx) {
        return mapping.count(idx) ? mapping[idx] : idx;
    }
    
    void reset() {
        mapping.clear();
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
