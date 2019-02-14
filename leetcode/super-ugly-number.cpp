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
        // 每个因子对应有一个要相乘的已知丑数，以生成下个丑数
        // 第j个因子primes[j]对应的丑数是seq[idx[j]]
        const int M = primes.size();
        vector<int> idx(M, 0); 
        for (int i = 1; i < n; i++) {
            int next = INT_MAX;
            for (int j = 0; j < M; j++) {
                next = min(next, seq[idx[j]] * primes[j]);
            }
            seq.push_back(next);
            for (int j = 0; j < M; j++) {
                if (next == seq[idx[j]] * primes[j]) idx[j]++;
            }
        }
        return seq.back();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
