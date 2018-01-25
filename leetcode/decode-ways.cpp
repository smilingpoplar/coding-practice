//
//  decode-ways
//  https://leetcode.com/problems/decode-ways/
//
//  Created by smilingpoplar on 15/5/20.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // 设f(i)表示s[0,i-1]的解码数，0<=i<=N
        // 先f(i)=0，若s[i-1]合法，f(i)+=f(i-1)；若s[i-2,i-1]合法，f(i)+=f(i-2)
        if (s.empty()) return 0;
        const int N = (int)s.size();
        vector<int> f(N + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= N; i++) {
            if (isValid(s, i - 1, i - 1)) f[i] += f[i - 1];
            if (isValid(s, i - 2, i - 1)) f[i] += f[i - 2];
        }
        return f[N];
    }
private:
    // s[start,end]是否合法
    bool isValid(const string &s, int start, int end) {
        if (start < 0 || start > end) return false;
        if (start == end) {
            return '1' <= s[end] && s[end] <= '9';
        }
        if (start + 1 == end) {
            return (s[start] == '1' && '0' <= s[end] && s[end] <= '9')
            || (s[start] == '2' && '0' <= s[end] && s[end] <= '6');
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.numDecodings("26");

    return 0;
}
