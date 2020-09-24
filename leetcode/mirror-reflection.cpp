//
//  mirror-reflection
//  https://leetcode.com/problems/mirror-reflection/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        // 反射相当于方形折叠展开、光线穿透直射
        // 当 (k*q)%p == 0 时到达接收器，k最小时 k*q == lcm(p,q) == p*q/gcd(p,q)
        // 所以，横向方形数k = p/gcd(p,q)，纵向方形数k*q/p = q/gcd(p,q)
        // 只需考查横向、纵向方形数的奇偶性
        int g = gcd(p, q);
        p /= g, p %= 2; // 横向
        q /= g, q %= 2; // 纵向

        if (p == 0) return 2;
        if (q == 0) return 0;
        return 1;
    }
    
    int gcd(int p, int q) {
        if (q == 0) return p;
        return gcd(q, p % q);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
