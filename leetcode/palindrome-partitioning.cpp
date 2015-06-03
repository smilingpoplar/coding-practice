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
        // 设f(i,j)表示s[i,j]是parlindrome，0<=i<=j<=N-1，则
        // f(i,j) = s[i]==s[j] && f(i+1,j-1), 当j-i>=2
        // f(i,j) = s[i]==s[j], 当j-i==1
        // f(i,j) = true, 当j-i==0
        const int N = (int)s.size();
        vector<vector<bool>> f(N, vector<bool>(N, 0));
        for (int i = 0; i < N; ++i) {
            f[i][i] = true;
        }
        for (int i = 0; i < N - 1; ++i) {
            f[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int distance = 2; distance < N; ++distance) {
            for (int i = 0; i < N - distance; ++i) {
                int j = i + distance;
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
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