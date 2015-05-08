//
//  climbing-stairs
//  https://leetcode.com/problems/climbing-stairs/
//
//  Created by smilingpoplar on 15/5/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // f[n]=f[n-1]+f[n-2]，f[0]=f[1]=1
        vector<int> f(n + 1);
        f[0] = f[1] = 1;
        for (size_t i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.climbStairs(2);
    
    return 0;
}
