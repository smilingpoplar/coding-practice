//
//  minimum-number-of-days-to-eat-n-oranges
//  https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> memo; // n=>minDays
        return dfs(n, memo);
    }
    
    int dfs(int n, unordered_map<int, int> &memo) {
        if (n <= 1) return n;
        if (memo.count(n)) return memo[n];
        
        // 在两种方案中选一种
        int a = n % 2 + dfs(n / 2, memo);
        int b = n % 3 + dfs(n / 3, memo);
        memo[n] = 1 + min(a, b);
        return memo[n];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
