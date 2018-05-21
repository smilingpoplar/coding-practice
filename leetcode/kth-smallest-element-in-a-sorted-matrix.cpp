//
//  kth-smallest-element-in-a-sorted-matrix
//  https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return INT_MIN;
        const int M = matrix.size();
        const int N = matrix[0].size();
        // 在值[matrix[0][0]..matrix[M-1][N-1]]中二分搜索找第k小的
        int l = matrix[0][0], u = matrix[M-1][N-1];
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (enough(matrix, mid, k)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    bool enough(vector<vector<int>>& matrix, int value, int k) {
        int count = 0;
        for (auto &row : matrix) {
            // 看每行<=value的数有几个
            count += upper_bound(row.begin(), row.end(), value) - row.begin();
        }
        return count >= k;
    }
};
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 每行是个有序数组，相当于在N个有序数组中找第k小的数
        // 用N元最小堆保存行编号，用N元数组保存各行的列索引
        const int N = matrix.size();
        vector<int> colIdx(N, 0);
        auto cmp = [&](int r1, int r2) { // 哪一行的当前元素较小
            if (colIdx[r1] == N) return true; // 相当于r1行元素无穷大
            if (colIdx[r2] == N) return false;
            return matrix[r1][colIdx[r1]] > matrix[r2][colIdx[r2]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < N; i++) {
            pq.push(i);
        }
        
        while (true) {
            int minR = pq.top();
            pq.pop();
            k--;
            if (k == 0) return matrix[minR][colIdx[minR]];

            colIdx[minR]++;
            pq.push(minR);
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
