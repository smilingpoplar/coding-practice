//
//  maximum-score-after-splitting-a-string
//  https://leetcode.com/problems/maximum-score-after-splitting-a-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        // score=zerosL+onesR=zerosL+(totalOnes-onesL)
        //      =zerosL-onesL+totalOnes
        // max{score}=max{zerosL-onesL}+totalOnes
        const int N = s.size();
        int zeros = 0, ones = 0, ans = INT_MIN;
        for (int i = 0; i < N; i++) {
            if (s[i] == '0') zeros++;
            else ones++;
            if (i < N - 1) ans = max(ans, zeros - ones); // 两子串非空
        }
        ans += ones;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
