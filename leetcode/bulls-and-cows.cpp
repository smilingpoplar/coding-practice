//
//  bulls-and-cows
//  https://leetcode.com/problems/bulls-and-cows/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        const int N = secret.size();
        int cow = 0, bull = 0;
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        for (int i = 0; i < N; i++) {
            if (secret[i] == guess[i]) {
                cow++;
            } else {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            bull += min(s[i], g[i]);
        }
        ostringstream oss;
        oss << cow << "A" << bull << "B";
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
