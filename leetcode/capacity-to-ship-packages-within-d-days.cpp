//
//  capacity-to-ship-packages-within-d-days
//  https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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

    bool enough(int capacity, vector<int>& weights, int D) {
        // 运载力capacity、天数days的关系
        int weight = 0, days = 1;
        for (int i = 0; i < weights.size(); i++) {
            weight += weights[i];
            if (weight > capacity) {
                days++;
                weight = weights[i];
            }
        }
        // capacity越大、days越小、days<=D越返回1
        return days <= D;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
