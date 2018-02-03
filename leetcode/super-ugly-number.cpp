//
//  super-ugly-number
//  https://leetcode.com/problems/super-ugly-number/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> seq;
        seq.push_back(1);
        // 每个因子对应一个要相乘的丑数，用以生成下个丑数
        // 第j个因子对应的丑数是seq[idx[j]]
        vector<int> idx(primes.size(), 0); 
        for (int i = 1; i < n; i++) {
            int next = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                next = min(next, seq[idx[j]] * primes[j]);
            }
            seq.push_back(next);
            for (int j = 0; j < primes.size(); j++) {
                if (next == seq[idx[j]] * primes[j]) idx[j]++;
            }
        }
        return seq[n - 1];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
