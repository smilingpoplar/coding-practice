//
//  elimination-game
//  https://leetcode.com/problems/elimination-game/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        // 设f(x)表示对x个人从1到x重新编号
        // n是奇数时，删除后重新编号的位置f(i)跟原来位置f(2i+1)关系是 2*f(i) => f(2i+1)
        // n是偶数时，从左往右删，则2*f(i) => f(2i)；从右往左删，则2*f(i)-1 => f(2i)
        // 综上，n是奇数或从左往右删时，f(n)=2*f(n/2)；否则，f(n)=2*f(n/2)-1
        return f(n, true);
    }
    
    int f(int n, bool fromLeft) {
        if (n == 1) return n;
        if (n % 2 == 1 || fromLeft) {
            return 2 * f(n/2, !fromLeft);
        }
        return 2 * f(n/2, !fromLeft) - 1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
