//
//  count-submatrices-with-all-ones
//  https://leetcode.com/problems/count-submatrices-with-all-ones/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // 把R行C列的矩阵看作R个以第r行为底的直方图
        if (mat.empty()) return 0;
        const int R = mat.size(), C = mat[0].size();
        int ans = 0;
        vector<int> h(C, 0);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (mat[r][c] == 0) h[c] = 0;
                else h[c]++;
            }
            ans += numSubmat(h);
        }
        return ans;
    }

    int numSubmat(vector<int>& h) { // 以第r行为底的直方图
        // 在直方图中统计全1子矩阵的个数
        // 找波峰，对应找下一个更小的数
        const int N = h.size();
        int ans = 0;
        vector<int> sum(N); // sum[i]保存右下角在(r,i)的子矩阵数
        stack<int> stk; // 保存下标
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && h[i] <= h[stk.top()]) {
                stk.pop();
            }
            int lo = stk.empty() ? -1 : stk.top();
            // 现在h[lo]<h[i]
            // (lo..i]位置的高度>h[i]，贡献右下角在(r,i)的子矩阵数(i-lo)*h[i]
            // (..lo]位置的高度<=h[i]，贡献右下角在(r,i)的子矩阵数已记录在sum[lo]中
            sum[i] += (i - lo) * h[i];
            if (lo >= 0) sum[i] += sum[lo];
            ans += sum[i];

            stk.push(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
