//
//  capacity-to-ship-packages-within-d-days
//  https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int maxW = 0, sumW = 0;
        for (int w : weights) {
            maxW = max(maxW, w);
            sumW += w;
        }
        
        int l = maxW, u = sumW;
        while (l <= u) {
            int m = l + (u - l) / 2;
            if (enough(m, weights, D)) {
                u = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    
    // 二分搜索条件enough(m)表示运载力m时能在days<=D天内运完
    bool enough(int m, vector<int>& weights, int D) {
        int weight = 0, days = 1;
        for (int i = 0; i < weights.size(); i++) {
            weight += weights[i];
            if (weight > m) {
                days++;
                weight = weights[i];
            }
        }
        return days <= D;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
