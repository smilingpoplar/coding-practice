//
//  palindrome-partitioning
//  https://leetcode.com/problems/palindrome-partitioning/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // 设f(i,j)表示s[i,j]是回文串，0<=i<=j<=N-1
        // f(i,j) = f(i+1,j-1) && s[i]==s[j], 当i+1>j-1时是空串f(i+1,j-1)为true
        const int N = (int)s.size();
        vector<vector<bool>> f(N, vector<bool>(N, false));
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i; j < N; j++) {
                f[i][j] = (i + 1 > j - 1 || f[i + 1][j - 1]) && s[i] == s[j];
            }
        }
        vector<vector<string>> result;
        vector<string> partition;
        dfs(0, s, f, partition, result);
        return result;
    }
private:
    void dfs(int start, const string &s, const vector<vector<bool>> &f,
             vector<string> &partition, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(partition);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (f[start][i]) {
                partition.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, s, f, partition, result);
                partition.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.partition("aab");
    for (const auto &partition : result) {
        for (const auto &palindrome : partition) {
            cout << palindrome << " ";
        }
        cout << endl;
    }
    
    return 0;
}