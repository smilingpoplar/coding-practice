//
//  decoded-string-at-index
//  https://leetcode.com/problems/decoded-string-at-index/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        // 先解码增加串长到N>=K
        long N = 0;
        int i = 0;
        for (; i < S.size() && N < K; i++) {
            if (isdigit(S[i])) N *= S[i] - '0';
            else N++;
        }
        // 再反向缩小N和K
        while (i--) {
            K %= N;
            if (K == 0 && isalpha(S[i])) return string(1, S[i]);

            if (isdigit(S[i])) N /= S[i] - '0';
            else N--;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
