//
//  combinations
//  https://leetcode.com/problems/combinations/
//
//  Created by smilingpoplar on 15/5/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        search(1, n, k, comb, ans);
        return ans;
    }

    void search(int startNum, const int n, const int k,
             vector<int> &comb, vector<vector<int>> &ans) {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        for (int i = startNum; i <= n; i++) {
            comb.push_back(i);
            search(i + 1, n, k, comb, ans);
            comb.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.combine(4, 2);
    for (const auto &combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
