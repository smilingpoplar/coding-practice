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
        // 看[0,n]的数中有多少个在某一位为1，要看这一位是 >1、=1、=0：
        //   当前位>1 => (高位数字+1)*当前位基数，如2225的百位（100、...、199、1100、...、1199、2100、...、2199）=> (2+1)*100
        //   当前位=1 => 高位数字*当前位基数+低位数字+1，如2125的百位（100、...、199、1100、...、1199、2100、...、2125）=> 2*100+26
        //   当前位=0 => 高位数字*当前位基数，如2025的百位（100、...、199、1100、...、1199）=> 2*100
        if (n <= 0) return 0;
        int count = 0;
        int base = 1;
        while (true) {
            int lower = n % base;
            int current = (n / base) % 10;
            int higher = n / base / 10;
            if (current > 1) {
                count += (higher + 1) * base;
            } else if (current == 1) {
                count += higher * base + lower + 1;
            } else {
                count += higher * base;
            }
            if (base > n / 10) break; // 防止溢出，base*10>n
            base *= 10;
        };
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.countDigitOne(13);
    
    return 0;
}
