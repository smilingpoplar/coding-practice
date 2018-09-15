//
//  random-point-in-non-overlapping-rectangles
//  https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> rects;
    vector<int> wsum;
public:
    Solution(vector<vector<int>> rects) : rects(rects) {
        // 以面积为权重选个rect，然后再rect中选个点
        int sum = 0;
        for (auto &rect : rects) {
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            wsum.push_back(sum);
        }
        srand(time(NULL));
    }
    
    vector<int> pick() {
        int rnd = rand() % wsum.back();
        int idx = upper_bound(wsum.begin(), wsum.end(), rnd) - wsum.begin();
        auto rect = rects[idx];
        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];
        return {x, y};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
