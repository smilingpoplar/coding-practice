//
//  maximum-of-absolute-value-expression
//  https://leetcode.com/problems/maximum-of-absolute-value-expression/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& x, vector<int>& y) {
        // |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j| (1)
        // 如果没有绝对值，式(1)=(arr1[i]+arr2[i]+i)-(arr1[j]+arr2[j]+j)
        // 令arr3[i]=arr1[i]+arr2[i]+i，式(1)=arr3[i]-arr3[j]，在arr3[]中找两数的最大差值
        // 现在加回绝对值，前两项各两种可能、第三项只一种可能，变成共有四种可能
        // 相当于在四种arr3[]中找两数的最大差值
        const int N = x.size();
        int ans = 0;
        vector<int> P{{-1, 1}};
        for (auto p1 : P) {
            for (auto p2 : P) {
                // 四种arr3[]，(x,y) => (p1*x, p2*y)
                // 每种都找其中两数的最大差值
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
