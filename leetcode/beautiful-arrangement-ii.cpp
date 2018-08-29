//
//  beautiful-arrangement-ii
//  https://leetcode.com/problems/beautiful-arrangement-ii/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        // 从[1..k+1]中头尾交错选择（有k个差值），剩下[k+2..n]按序输出
        vector<int> ans;
        for (int i = 1, j = k + 1, c = 0; i <= j; c++) {
            if (c % 2 == 0) ans.push_back(i++);
            else ans.push_back(j--);
        }
        for (int i = k + 2; i <= n; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
