//
//  maximum-of-absolute-value-expression
//  https://leetcode.com/problems/maximum-of-absolute-value-expression/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& x, vector<int>& y) {
        // 把arr1看作x坐标，arr2看作y坐标，数组索引idx看作z坐标
        // 本题变成：找任意两点{ (x1,y1,z1), (x2,y2,z2) }的最大hamming距离
        // (x,y)的hamming距离|x|+|y|，为去掉绝对值符号 <==>
        // 把(x,y)分别映射到四个象限，然后距离取x+y，hamming距离一定在其中
        const int N = x.size();
        int ans = 0;
        vector<int> P({-1, 1});
        for (auto p1 : P) {
            for (auto p2 : P) {
                // 把(x,y)分别映射到四个象限，(x,y) => (p1*x, p2*y)
                int theMin = INT_MAX, theMax = INT_MIN;
                for (int i = 0; i < N; i++) {
                    int val = p1 * x[i] + p2 * y[i] + i;
                    theMin = min(theMin, val);
                    theMax = max(theMax, val);
                    ans = max(ans, theMax - theMin);
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
