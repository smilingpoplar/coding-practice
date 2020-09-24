//
//  x-of-a-kind-in-a-deck-of-cards
//  https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // 卡i有cnt[i]张，所有cnt[i]%x==0，x是所有cnt[i]的gcd
        unordered_map<int, int> cnt;
        for (int card : deck) cnt[card]++;
        int x = 0;
        for (auto &e : cnt) {
            x = gcd(x, e.second);
        }
        return x >= 2;
    }
    
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
