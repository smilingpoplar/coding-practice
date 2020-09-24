//
//  remove-9
//  https://leetcode.com/problems/remove-9/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int newInteger(int n) {
        // 删除9后的数正好就是九进制数，这题就是把十进制转成九进制
        // 扩展：如果删除7，还是九进制，只是结果需映射7=>8,8=>9。
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
