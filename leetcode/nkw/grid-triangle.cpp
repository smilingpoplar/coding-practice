//
//  grid-triangle
//  NC342 格点三角形
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getNums(int n, int m) {
        // 直角顶点有 n*m 中位置选择，另两个顶点分别有 n-1 种、m-1 种选择
        const int MOD = 1e9 + 7;
        long ans = ((long)n * m) % MOD;
        ans = (ans * (n - 1)) % MOD;
        ans = (ans * (m - 1)) % MOD;
        return ans;
    }
};