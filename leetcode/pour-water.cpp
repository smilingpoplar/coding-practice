//
//  pour-water
//  https://leetcode.com/problems/pour-water/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        // 模拟倒水，先尽量往左边低地流、再尽量往右边低地流
        const int N = heights.size();
        while (V--) {
            int low = K;
            for (int i = K; i > 0 && heights[i-1] <= heights[i]; i--) { // <=的地儿都要查
                if (heights[i-1] < heights[i]) low = i-1;
            }
            if (low == K) { // 再尝试往右流
                for (int i = K; i < N - 1 && heights[i+1] <= heights[i]; i++) {
                    if (heights[i+1] < heights[i]) low = i+1;
                }
            }
            heights[low]++;
        }
        return heights;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
