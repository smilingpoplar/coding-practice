//
//  k-empty-slots
//  https://leetcode.com/problems/k-empty-slots/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        // 各个位置的花哪天开
        const int N = flowers.size();
        vector<int> days(N);
        for (int i = 0; i < N; i++) {
            days[flowers[i] - 1] = i + 1;
        }
        // 要找相隔k的两个位置lo和hi（hi-lo==k+1），使所有位置i（lo<x<hi）都满足
        // days[i]>days[lo]和days[i]>days[hi]
        int ans = INT_MAX;
        for (int lo = 0, hi = lo + k + 1; hi < N; hi = lo + k + 1) {
            int i = lo + 1;
            while (days[i] > days[lo] && days[i] > days[hi]) i++;
            if (i == hi) { // (lo..hi)中间k个位置满足条件
                int day = max(days[lo], days[hi]);
                ans = min(ans, day);
            }
            lo = i;
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
