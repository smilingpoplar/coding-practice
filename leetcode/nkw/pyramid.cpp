//
//  pyramid
//  NC341 金字塔
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getNums(int n) {
        // 各层点数：1, 1+2, 1+2+3, 1+2+3+4, ... 即 n(n+1)/2 = (n^2+n)/2
        // 所有层点数：(平方和+累加和)/2 = (n(n+1)(2n+1)/6 + n(n+1)/2) /2 = n(n+1)(n+2)/6
        const int MOD = 1e9 + 7;
        return ((long(n) * (n + 1)) % MOD * (n + 2) / 6) % MOD;
    }
};