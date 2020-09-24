//
//  pascals-triangle-ii
//  https://leetcode.com/problems/pascals-triangle-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // pascal每行除首尾外：row[i][j] = row[i-1][j-1] + row[i-1][j]，0<j<i
        // 省掉i这维，i仍从左往右遍历；row[j-1]要表示旧值row[i-1][j-1]，j从右往左遍历
        vector<int> row;
        for (int i = 0; i < numRows; i++) {
            for (int j = i - 1; j > 0; j--) {
                row[j] += row[j-1];
            }
            row.push_back(1); // 行末的1
        }
        return row;
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
