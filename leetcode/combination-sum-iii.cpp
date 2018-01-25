//
//  combination-sum-iii
//  https://leetcode.com/problems/combination-sum-iii/
//
//  Created by smilingpoplar on 15/5/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        dfs(1, k, n, combination, result);
        return result;
    }
private:
    void dfs(int start, int k, int n,
             vector<int> &combination, vector<vector<int>> &result) {
        if (k == 0 && n == 0) {
            result.push_back(combination);
            return;
        }
        if (k <= 0 || n <= 0) return;
        for (int i = start; i <= 9; i++) {
            combination.push_back(i);
            dfs(i + 1, k - 1, n - i, combination, result);
            combination.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.combinationSum3(3, 9);
    for (const auto &combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
