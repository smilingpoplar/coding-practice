//
//  number-of-ways-to-reorder-array-to-get-same-bst
//  https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    vector<vector<int>> C;
    const int MOD = 1e9 + 7;
public:
    int numOfWays(vector<int>& nums) {
        const int N = nums.size();
        // 组合数nCk为杨辉三角中C[n][k]
        C = vector<vector<int>>(N + 1, vector<int>(N + 1));
        C[0][0] = 1;
        for (int i = 1; i < N; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
        return ways(nums) - 1;
    }

    int ways(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return 1;

        vector<int> left, right;
        for (int i = 1; i < N; i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        return weave(left, right);
    }

    int weave(vector<int>& A, vector<int>& B) {
        // 左右两数组交织，可保持二叉树不变
        int nCk = C[A.size() + B.size()][A.size()];
        long left = ways(A), right = ways(B);
        return (((left * right) % MOD) * nCk) % MOD;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
