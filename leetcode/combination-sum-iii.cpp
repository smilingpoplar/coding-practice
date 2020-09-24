//
//  combination-sum-iii
//  https://leetcode.com/problems/combination-sum-iii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        search(k, n, 1, comb, ans);
        return ans;
    }
private:
    void search(int k, int sum, int startNum, 
             vector<int> &comb, vector<vector<int>> &ans) {
        if (k == 0 && sum == 0) {
            ans.push_back(comb);
            return;
        }
        if (k <= 0 || sum <= 0) return;
        
        for (int i = startNum; i <= 9; i++) {
            comb.push_back(i);
            search(k - 1, sum - i, i + 1, comb, ans); // 每个数只能选1次
            comb.pop_back();
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
