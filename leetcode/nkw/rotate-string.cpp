//
//  rotate-string-ii
//  NC253 旋转字符串（二）
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool solve(string A, string B) {
        // 如果A左旋后可以得到B，那么AA中包含B
        const int N = A.size();
        if (N < 2 || N != B.size()) return false;
        return (A + A).substr(1, 2 * N - 2).find(B) != string::npos;
    }
};