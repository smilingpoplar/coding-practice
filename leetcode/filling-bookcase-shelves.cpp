//
//  filling-bookcase-shelves
//  https://leetcode.com/problems/filling-bookcase-shelves/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        // 设dp[i+1]表示books[0..i]子问题的最小高度，
        // books[i]可以和前面的书一起books[j..i]放在一层，
        // dp[i+1] = min(dp[j]+max( books[j..i][1] ))
        // 其中j满足 j<=i && sum( books[j..i][0] ) <= shelf_width
        const int N = books.size();
        vector<int> dp(N + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            int levelWidth = 0, levelHeight = 0;
            for (int j = i; j >= 0 && levelWidth + books[j][0] <= shelf_width; j--) {
                levelWidth += books[j][0];
                levelHeight = max(levelHeight, books[j][1]);
                dp[i+1] = min(dp[i+1], dp[j] + levelHeight);
            }
        }
        return dp[N];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
