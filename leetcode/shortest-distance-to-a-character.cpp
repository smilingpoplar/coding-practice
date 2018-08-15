//
//  shortest-distance-to-a-character
//  https://leetcode.com/problems/shortest-distance-to-a-character/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        // 往右扫一遍、往左扫一遍
        const int N = S.size();
        int pos = -N;
        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            if (S[i] == C) pos = i;
            ans[i] = i - pos;
        }
        // 已知C在S中肯定存在，现在0<=pos<N
        for (int i = N - 1; i >= 0; i--) {
            if (S[i] == C) pos = i;
            ans[i] = min(ans[i], abs(i - pos));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
