//
//  filling-bookcase-shelves
//  https://leetcode.com/problems/filling-bookcase-shelves/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        // 设dp[i]表示books[0..i)子问题的最小高度，
        // books[i-1]可以和books[j..i-1)放在一层，即books[j..i-1]在一层，
        //  j<i 且 sum(books[j..i-1][0])<=shelf_width
        // dp[i] = min{ dp[j] + max{ books[j..i-1][1] }}
        const int N = books.size();
        vector<int> dp(N + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            int width = 0, height = 0;
            for (int j = i - 1; j >= 0 && width + books[j][0] <= shelf_width; j--) {
                width += books[j][0];
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], dp[j] + height);
            }
        }
        return dp[N];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
