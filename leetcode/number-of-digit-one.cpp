//
//  number-of-digit-one
//  https://leetcode.com/problems/number-of-digit-one/
//
//  Created by smilingpoplar on 15/7/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        // 从低位到高位一位位地看，某一位有多少个'1'，要看该位是 <1、>1、=1？
        // 需要用该位代表的数base、左边（不含该位）构成的数higher、右边（不含该位）构成的数lower。
        //   该位<1 => higher*base
        //      如2025的百位（100、...、199、1100、...、1199）=> 2*100
        //   该位>1 => (higher+1)*base
        //      如2225的百位（100、...、199、1100、...、1199、2100、...、2199）=> (2+1)*100
        //   该位=1 => higher*base + (lower+1)
        //      如2125的百位（100、...、199、1100、...、1199、2100、...、2125）=> 2*100+26
        if (n <= 0) return 0;
        int ans = 0;
        long base = 1;
        while (base <= n) {
            int lower = n % base, curr = (n / base) % 10, higher = (n / base) / 10;
            if (curr < 1) {
                ans += higher * base;
            } else if (curr > 1) {
                ans += (higher + 1) * base;
            } else {
                ans += higher * base + (lower + 1);
            }
            base *= 10;
        };
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.countDigitOne(13);
    
    return 0;
}
