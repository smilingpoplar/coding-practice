//
//  push-dominoes
//  https://leetcode.com/problems/push-dominoes/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        // 计算各牌的受力
        const int N = dominoes.size();
        vector<int> forces(N, 0);
        // 从左往右扫，遇R施加右向的力N、且力随距离衰减
        int force = 0;
        for (int i = 0; i < N; i++) {
            if (dominoes[i] == 'R') force = N;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }
        // 从右往左扫，遇L施加左向的力N、且力随距离衰减
        force = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') force = N;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }
        
        string ans;
        for (int force : forces) {
            if (force > 0) ans += 'R';
            else if (force < 0) ans += 'L';
            else ans += '.';
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
