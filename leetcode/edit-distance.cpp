//
//  edit-distance
//  https://leetcode.com/problems/edit-distance/
//
//  Created by smilingpoplar on 15/8/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 动态规划，设f(i,j)表示s1[0,i)和s2[0,j)的最小编辑距离
        // f(i,j) = min{ f(i-1,j)+1, /*添加*/
        //               f(i,j-1)+1, /*删除*/
        //               f(i-1,j-1)+(s1[i-1]==s2[j-1]?0:1) /*替换*/}
        const int M = (int)word1.size();
        const int N = (int)word2.size();
        vector<vector<int>> f(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; ++i) f[i][0] = i;
        for (int j = 1; j <= N; ++j) f[0][j] = j;
        
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                f[i][j] = min(min(f[i - 1][j] + 1, f[i][j - 1] + 1),
                              f[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
            }
        }
        return f[M][N];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.minDistance("cat", "ha");
    
    return 0;
}
