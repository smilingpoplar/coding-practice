//
//  koko-eating-bananas
//  https://leetcode.com/problems/koko-eating-bananas/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // 吃完piles[i]需要(piles[i]+K-1)/K小时
        // sum{ (piles[i]+K-1)/K } <= H，最小化K
        // 上式中K越大越为true、K越小越为false，符合二分搜索[0 0 .. 0 1 1 ..]的条件
        // 二分搜索找第一个符合上式的K
        int lo = 1, hi = 1e9;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (enough(piles, mid, H)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    bool enough(vector<int> &piles, int K, int H) {
        int sum = 0;
        for (int pile : piles) {
            sum += (pile + K - 1) / K;
        }
        return sum <= H;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
