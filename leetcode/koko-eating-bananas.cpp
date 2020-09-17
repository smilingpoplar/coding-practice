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
        int lo = 1, hi = 1e9;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (enough(mid, piles, H)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    bool enough(int K, vector<int> &piles, int H) {
        // 吃完piles[i]需要(piles[i]+K-1)/K小时
        // sum{ (piles[i]+K-1)/K }是K的递减函数，
        // sum<=H 符合二分搜索[0 0 .. 0 1 1 ..]的条件
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
