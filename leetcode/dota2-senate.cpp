//
//  dota2-senate
//  https://leetcode.com/problems/dota2-senate/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        const int N = senate.size();
        queue<int> R, D;
        for (int i = 0; i < N; i++) {
            if (senate[i] == 'R') R.push(i);
            else D.push(i);
        }
        while (!R.empty() && !D.empty()) {
            int r = R.front(); R.pop();
            int d = D.front(); D.pop();
            if (r < d) {
                R.push(r + N);
            } else {
                D.push(d + N);
            }
        }
        if (!R.empty()) return "Radiant";
        return "Dire";
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
