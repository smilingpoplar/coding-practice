//
//  longest-AA-type-substring
//

#include <iostream>

using namespace std;

class Solution {
public:
    int solve(string str) {
        // 最长的AA类型的子串
        const int N = str.size();
        int len = 0;
        for (int l = N / 2; l > 0; l--) {      // 枚举长度
            for (int s = 0; s < N - l; s++) {  // 枚举起点
                if (str[s] == str[s + l]) {
                    len++;
                } else {
                    len = 0;
                }
                if (len == l) return 2 * l;
            }
        }
        return 0;
    }
};
