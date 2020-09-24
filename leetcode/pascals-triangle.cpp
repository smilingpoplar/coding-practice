//
//  pascals-triangle
//  https://leetcode.com/problems/pascals-triangle/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // pascal每行除首尾外：row[i][j] = row[i-1][j-1] + row[i-1][j]，0<j<i
        // 省掉i这维，i仍从左往右遍历；row[j-1]要表示旧值row[i-1][j-1]，j从右往左遍历
        vector<vector<int>> ans;
        vector<int> row;
        for (int i = 0; i < numRows; i++) {
            for (int j = i - 1; j > 0; j--) {
                row[j] += row[j-1];
            }
            row.push_back(1); // 行末的1
            ans.push_back(row);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {   
    return 0;
}
