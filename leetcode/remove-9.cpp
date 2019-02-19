//
//  remove-9
//  https://leetcode.com/problems/remove-9/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int newInteger(int n) {
        // 删除9后的数正好就是九进制数。
        // 1,2,3,4,5,6,7,8,
        // 10,11,12,13,14,15,16,17,18,
        // 20,21,22,23,24,25,26,27,28,
        // ...
        // 80,81,82,83,84,85,86,87,88,
        // 100,101,102,...
        // 这题就是把十进制转成九进制。
        // 扩展：如果删除7，还是九进制，只是映射7=>8,8=>9。
        int ans = 0, base = 1;
        while (n) {
            ans += (n % 9) * base; // 从后往前拼上
            n /= 9;
            base *= 10;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
