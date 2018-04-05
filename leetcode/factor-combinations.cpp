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
    
    void search(int n, int start, vector<int> &comb, vector<vector<int>> &ans) {
        if (n == 1) {
            if (comb.size() > 1) ans.push_back(comb);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            if (i > sqrt(n)) i = n; // (sqrt(n)..n)的值不可能是因子    
            if (n % i == 0) {
                comb.push_back(i);
                search(n / i, i, comb, ans);
                comb.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
