//
//  output-contest-matches
//  https://leetcode.com/problems/output-contest-matches/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> team(n);
        for (int i = 0; i < n; i++)
            team[i] = to_string(i + 1);

        // 已知n=2^k
        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                team[i] = "(" + team[i] + "," + team[n-1-i] + ")";
            }
            n /= 2;
        }
        return team[0];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
