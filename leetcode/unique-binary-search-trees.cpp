//
//  unique-binary-search-trees
//  https://leetcode.com/problems/unique-binary-search-trees/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // 设dp[k]表示k个节点时bst的结构数，1<=k<=n
        // 当bst以数字i作根节点时，左子树[1,i-1]有dp[i-1]种，右子树[i+1,k]有dp[k-i]种，
        // 故 dp[k] = sum( dp[i-1]*dp[k-i] ), 1<=i<=k
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int k = 1; k <= n; k++) {
            int sum = 0;
            for (int i = 1; i <= k; i++) {
                sum += dp[i - 1] * dp[k - i];
            }
            dp[k] = sum;
        }

        return dp[n];
    }
};

int main(int argc, const char* argv[]) {
    Solution solution;
    cout << solution.numTrees(3);

    return 0;
}
