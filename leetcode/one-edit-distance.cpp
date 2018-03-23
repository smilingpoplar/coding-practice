//
//  one-edit-distance
//  https://leetcode.com/problems/one-edit-distance/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        const int M = s.size();
        const int N = t.size();
        if (abs(M - N) > 1) return false;

        int maxI = min(M, N);
        for (int i = 0; i < maxI; i++) {
            if (s[i] == t[i]) continue;
            // 单字母替换、添加或删除
            if (M == N) return s.substr(i+1) == t.substr(i+1);
            if (M < N) return s.substr(i) == t.substr(i+1);
            return s.substr(i+1) == t.substr(i);
        }
        // 所有前面都相同，需某串多一个字母
        return M != N;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
