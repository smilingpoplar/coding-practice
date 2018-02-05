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
                // 奇数n=2k+1，有n-1=2k、n+1=2(k+1)，下一步k和k+1不是奇数就是偶数，选偶数的分支
                // 特例是最终若在k=1或2间选（这时n=3），要选1（选n-1的分支）
                if ((n - 1) % 4 == 0 || n == 3) { // k=(n-1)/2是偶数，或n==3，选n-1分支
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
