//
//  count-primes
//  https://leetcode.com/problems/count-primes/
//
//  Created by smilingpoplar on 15/6/23.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // 素数筛法
        vector<bool> prime(n, true);
        for (int i = 2; i * i < n; i++) {
            if (!prime[i]) continue;
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) count++;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.countPrimes(1000);
    
    return 0;
}
