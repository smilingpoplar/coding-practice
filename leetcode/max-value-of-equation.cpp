//
//  max-value-of-equation
//  https://leetcode.com/problems/max-value-of-equation/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // 因为xi<xj，要最大化(yi-xi)+(yj+xj)
        // 从左往右扫描，对于特定的j点，要最大化它前面点的yi-xi
        // 求[j-k..j)滑动窗口内的最大yi-xi值，用单调递减队列
        int ans = INT_MIN;
        deque<array<int, 2>> dq; // 保存{yi-xi, xi}
        for (const auto& p : points) {
            while (!dq.empty() && p[0] - dq[0][1] > k) { // xj-xi
                dq.pop_front();
            }
            // 有效的k长窗口
            if (!dq.empty()) {
                ans = max(ans, dq[0][0] + p[1] + p[0]);
            }
            
            while (!dq.empty() && p[1] - p[0] > dq.back()[0]) {
                dq.pop_back();
            }
            dq.push_back({p[1] - p[0], p[0]});
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
