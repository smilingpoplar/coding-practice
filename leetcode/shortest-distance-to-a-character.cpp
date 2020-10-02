//
//  shortest-distance-to-a-character
//  https://leetcode.com/problems/shortest-distance-to-a-character/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        // 正反各扫一遍
        // 正向看距离左边e的最小距离，反向看距离右边e的最小距离
        const int N = S.size();
        vector<int> ans(N);
        int idx = -N;
        for (int i = 0; i < N; i++) {
            if (S[i] == C) idx = i;
            ans[i] = i - idx;
        }
        for (int i = idx - 1; i >= 0; i--) {
            if (S[i] == C) idx = i;
            ans[i] = min(ans[i], idx - i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
