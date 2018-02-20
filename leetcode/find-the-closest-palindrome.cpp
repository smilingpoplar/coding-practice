//
//  find-the-closest-palindrome
//  https://leetcode.com/problems/find-the-closest-palindrome/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        // 如果最近回文数与原数的数字个数相同，一定是先把中间数字+0、+1、-1，再把前半部分翻转；
        // 如果数字个数不同，那一定是100...01、或者99...9
        vector<long> cands;
        cands.push_back(pow(10, n.size()) + 1);
        cands.push_back(pow(10, n.size() - 1) - 1);
        long numN = stol(n);
        for (int i = -1; i <= 1; i++) {
            auto cand = stol(mirror(n, i));
            if (cand != numN) cands.push_back(cand);
        }
        long minCand = *min_element(cands.begin(), cands.end(), [&numN](long a, long b) {
            return abs(a - numN) < abs(b - numN);
        });
        return to_string(minCand);
    }
    
    string mirror(const string &n, int delta = 0) {
        const int len = n.size();
        string prefix = n.substr(0, (len + 1)/ 2);
        if (delta != 0) {
            long prefixNum = stol(prefix);
            prefixNum += delta;
            prefix = to_string(prefixNum);
        }
        return prefix + string(prefix.rbegin() + (len % 2), prefix.rend());
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
