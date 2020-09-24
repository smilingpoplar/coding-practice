//
//  kth-smallest-element-in-a-sorted-matrix
//  https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return INT_MIN;
        const int R = matrix.size(), C = matrix[0].size();
        // 设第k小的数为x，x在范围[matrix[0][0]..matrix[R-1][C-1]]
        // 设二分搜索条件enough(x)表示"<=x的个数"count>=k
        int l = matrix[0][0], u = matrix[R-1][C-1];
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (enough(mid, matrix, k)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    bool enough(int value, vector<vector<int>>& matrix, int k) {
        int count = 0;
        for (auto &row : matrix) {
            // 看每行<=value的数有多少
            count += upper_bound(row.begin(), row.end(), value) - row.begin();
        }
        return count >= k;
    }
};
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 在N行的有序数组中找第k小的数
        // 用最小堆保存行索引，用colIdx[]保存各行的列索引
        // 第r行当前元素是matrix[r][colIdx[r]]
        const int N = matrix.size();
        vector<int> colIdx(N, 0);
        auto cmp = [&](int r1, int r2) {
            if (colIdx[r1] == N) return true; // 相当于r1行元素无穷大
            if (colIdx[r2] == N) return false;
            return matrix[r1][colIdx[r1]] > matrix[r2][colIdx[r2]]; // 最小堆
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < N; i++) pq.push(i);
        
        while (--k) { // 弹出k-1个数
            int minR = pq.top();
            pq.pop();
            colIdx[minR]++;
            pq.push(minR);
        }
        int minR = pq.top();
        return matrix[minR][colIdx[minR]];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
