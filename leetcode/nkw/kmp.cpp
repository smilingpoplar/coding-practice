//
//  kmp
//  NC149 kmp算法
//

#include <iostream>

using namespace std;

class Solution {
public:
    int kmp(string pattern, string text) {
        const int N = text.size(), M = pattern.size();
        vector<int> b = buildBorder(pattern);

        int ans = 0;
        int t = 0, p = 0;
        while (t < N) {
            while (p >= 0 && text[t] != pattern[p]) {
                p = b[p];
            }
            t++, p++;

            if (p == M) {
                ans++;     // 匹配成功
                p = b[p];  // 继续寻找下一匹配
            }
        }
        return ans;
    }

    vector<int> buildBorder(const string& pattern) {
        const int M = pattern.size();
        // 设b[i]表示长为i的前缀pattern[0..i-1]的最大边界长
        vector<int> b(M + 1);
        int i = 0, j = -1;  // 空串，无边界
        b[i] = j;
        while (i < M) {
            while (j >= 0 && pattern[i] != pattern[j]) {  // 当前边界不能扩展，性质2
                j = b[j];                                 // 考虑下一小的边界，性质1
            }
            // 扩展边界
            i++, j++;
            b[i] = j;
        }
        return b;
    }
};
