//
//  unique-binary-search-trees
//  https://leetcode.com/problems/unique-binary-search-trees/
//
//  Created by smilingpoplar on 15/5/23.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // 设f(k)表示k个节点时bst的排列数，当bst以数字i作根节点时，左子树[1,i-1]有f(i-1)种排列数，右子树[i+1,k]有f(k-i)种排列数，
        // 故 f(k) = sum( f(i-1)*f(k-i) ) 1<=i<=k
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (int k = 1; k <= n; ++k) {
            int sum = 0;
            for (int i = 1; i <= k; ++i) {
                sum += f[i - 1] * f[k - i];
            }
            f[k] = sum;
        }
        
        return f[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.numTrees(3);
    
    return 0;
}
