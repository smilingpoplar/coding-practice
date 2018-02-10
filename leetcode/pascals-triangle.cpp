//
//  pascals-triangle
//  https://leetcode.com/problems/pascals-triangle/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // pascal三角每行除首尾以外的通项：p(i,j) = p(i-1,j-1) + p(i-1,j)，0<j<i<N
        // 在i的递增循环j的递减循环中降维：p(j) = p(j-1) + p(j)
        vector<vector<int>> ans;
        if (numRows <= 0) return ans;

        vector<int> p;
        for (int i = 0; i < numRows; i++) {
            for (int j = i - 1; j > 0; j--) {
                p[j] += p[j-1];
            }
            p.push_back(1); // 行末的1
            ans.push_back(p);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {   
    return 0;
}
