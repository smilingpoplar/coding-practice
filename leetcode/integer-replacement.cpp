//
//  integer-replacement
//  https://leetcode.com/problems/integer-replacement/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) return 32;
        
        int count = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                // 奇数是到底是往上n+1还是往下n-1？设n=2k+1（k>=0），有n-1=2k、n+1=2(k+1)，
                // 下下步k和k+1一个奇数一个偶数，优先选下下步是偶数的分支！
                // 若要选n-1分支，要求k=(n-1)/2是偶数，(n-1)%4==0
                // 特别地，n==3时选n-1分支下下步1、选n+1分支下下步2，选n-1分支更快结束
                if ((n - 1) % 4 == 0 || n == 3) {
                    n--;
                } else {
                    n++;
                }
            }
            count++;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
