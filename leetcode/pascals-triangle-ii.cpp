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
    vector<int> getRow(int rowIndex) {
        // pascal三角的通项：p(i,j) = p(i-1,j-1) + p(i-1,j)，1<=j<i<=rowIndex
        // 在i的递增循环j的递减循环中降维：p(j) = p(j-1) + p(j)，1<=j<i<=rowIndex
        if (rowIndex < 0) return {};
        vector<int> p;
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i - 1; j >= 1; --j) { // i>=2进循环
                p[j] += p[j - 1];
            }
            p.push_back(1); // 行末的1
        }
        return p;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.getRow(5);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
