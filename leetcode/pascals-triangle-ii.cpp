//
//  pascals-triangle-ii
//  https://leetcode.com/problems/pascals-triangle-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int k) {
        // pascal三角的通项：p(i,j) = p(i-1,j-1) + p(i-1,j)，1<=i<=k && 1<=j<k
        // 在i的递增循环j的递减循环中降维，p(j) = p(j-1) + p(j)
        if (k < 0) return {};
        vector<int> p(k + 1, 0);
        p[0] = 1;
        for (int i = 1; i <= k; ++i) {
            for (int j = k - 1; j >= 1; --j) {
                p[j] += p[j - 1];
            }
            p[k] = 1; // 行末的1
        }
        return p;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.getRow(20);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
