//
//  hand-of-straights
//  https://leetcode.com/problems/hand-of-straights/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> cnt; // card=>count
        for (int card : hand) {
            cnt[card]++;
        }
        
        for (auto &e : cnt) {
            int count = e.second;
            if (count > 0) { // [card..card+W)都减count
                int card = e.first;
                for (int i = 0; i < W; i++) {
                    cnt[card+i] -= count;
                    if (cnt[card+i] < 0) return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
