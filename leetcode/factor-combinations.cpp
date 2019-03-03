//
//  factor-combinations
//  https://leetcode.com/problems/factor-combinations/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        search(n, 2, comb, ans);
        return ans;
    }
    
    void search(int n, int startNum, vector<int> &comb, vector<vector<int>> &ans) {
        if (n == 1) {
            ans.push_back(comb);
            return;
        }
        
        for (int i = startNum; i * i <= n; i++) {
            if (n % i == 0) {
                comb.push_back(i);
                search(n / i, i, comb, ans);
                // 本次得到两个因子
                comb.push_back(n / i);
                ans.push_back(comb);
                comb.pop_back();
                comb.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
