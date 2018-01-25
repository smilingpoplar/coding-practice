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
        // pascal三角的通项：p(i,j) = p(i-1,j-1) + p(i-1,j)，1<=j<i<numRows
        // 在i的递增循环j的递减循环中降维：p(j) = p(j-1) + p(j)，1<=j<i<numRows
        
        vector<vector<int>> result;
        if (numRows <= 0) return result;

        vector<int> p;
        for (int i = 0; i < numRows; i++) {
            for (int j = i - 1; j >= 1; j--) { // i>=2进循环
                p[j] += p[j - 1];
            }
            p.push_back(1); // 行末的1
            result.push_back(p);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.generate(10);
    for (const auto &row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
