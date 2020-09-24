//
//  magnetic-force-between-two-balls
//  https://leetcode.com/problems/magnetic-force-between-two-balls/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // 在允许的不同位置放球，使它们尽可能分散
        // 最小距离dist的取值在[1..position[-1]-1]
        // 二分搜索猜dist，找满足条件最后一个，修改标准二分搜索写法：
        // 1. 条件式中去掉等号，2. 最终要找的位置为lo
        sort(position.begin(), position.end());
        int lo = 0, hi = position.back();
        int ans = 0;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (enough(mid, position, m)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return lo; // 修改2
    }
    
    bool enough(int dist, vector<int>& position, int m) {
        // 两球间的最小距离dist一确定，position[]中能放的球数count也确定
        // count(dist)是关于dist的递减函数，
        // count(dist)<m符合二分搜索的条件形式[0..0 1 1..]，
        // 用<m而不是<=m，因为要找满足条件的最后一个，条件式中去掉等号
        const int N = position.size();
        int nextPos = 0, count = 0;
        for (int i = 0; i < N; i++) {            
            if (position[i] >= nextPos) {
                count++;
                nextPos = position[i] + dist;
            }
        }
        return count < m; // 修改1
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
