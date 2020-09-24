//
//  smallest-good-base
//  https://leetcode.com/problems/smallest-good-base/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        // n = 111..11（x个1）= b^0+b^1+b^2+...+b^(x-1) = (b^x-1)/(b-1)
        // 要基数b尽量小，则位数x尽量大。b取值范围[2..n-1]：b=2时n=2^x-1，x=lg(n+1)；b=n-1时x=2；故x=[2..lg(n+1)]
        // 由二项式定理(b+1)^(x-1)=b^0+?b^1+?b^2+...+b^(x-1) > b^0+b^1+b^2+...+b^(x-1)=n，
        // 又n > b^(x-1)，故 b+1 > pow(n,1/(x-1)) > b，b = floor( pow(n,1/(x-1)) )
        long long num = stoll(n);
        for (int x = log2(num + 1); x >= 2; x--) {
            int b = pow(num, 1.0 /(x - 1));
            if (calSum(b, x) == num) return to_string(b);
        }
        return to_string(num - 1);
    }

    // 对特定b和x计算等比级数n。
    // 不能用等比公式，因为pow()浮点计算有精度问题！
    long long calSum(int b, int x) {
        long long curr = 1, sum = 1;
        for (int i = 1; i <= x - 1; i++) {
            curr *= b;
            sum += curr;
        }
        return sum;
    } 
};

int main(int argc, const char * argv[]) {
    return 0;
}
