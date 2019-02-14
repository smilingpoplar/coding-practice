//
//  prime-palindrome
//  https://leetcode.com/problems/prime-palindrome/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int primePalindrome(int N) {
        // 先生成回文，再判断是素数。因为1<=N<=10^8，只需[1..10^5)的数生成回文：
        //   正反拼接（偶数位）或 正反拼接且最后一位重合（奇数位）
        // 特别地，所有偶位数回文都是11的倍数
        //   因为1001%11=(1111-11*10)%11=0、100001%11=(111111-1111*10)%11=0、...
        //   所以abccba%11=(a*100001+b*1001*10+11*100)%11=0
        // 所以偶数位回文只有11是素数回文，而11只有当8<=N<=11时才返回。
        // 接下来只需判断奇数位回文
        if (8 <= N && N <= 11) return 11;
        for (int i = 1; i < 1e5; i++) {
            string s = to_string(i);
            s += string(s.rbegin() + 1, s.rend());
            int x = stoi(s);
            if (x >= N && isPrime(x)) return x;
        }
        return -1;
    }
    
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
