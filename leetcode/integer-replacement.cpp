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
        if (n == INT_MAX) return 32; // n=2^31-1
        
        int count = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                // n为奇数时到底往上n+1还是往下n-1？要看下下步的奇偶，哪个偶数选哪个。
                // 设n=2k+1 (k>=0)，有n-1=2k、n+1=2(k+1)，下下步的k和k+1一奇一偶，
                // k是偶数时，(n-1)%4==0，选n-1分支；否则，选n+1分支
                // 特例是n==3选n-1分支，因为选n-1分支要2步、选n+1分支要3步
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
