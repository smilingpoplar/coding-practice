//
//  random-point-in-non-overlapping-rectangles
//  https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> rects;
    vector<int> wsum;
public:
    Solution(vector<vector<int>> rects) : rects(rects) {
        // 以面积为权重选个rect，然后在rect中选个点
        int sum = 0;
        for (auto &rect : rects) {
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            wsum.push_back(sum);
        }
        srand(time(NULL));
    }
    
    vector<int> pick() {
        // 按概率选中某项 <=> 从左往右按累计概率选中某项（从左往右保证了排除掉前面的累计概率，只剩当前项的概率）
        int rnd = rand() % wsum.back();
        // rnd<wsum[i]时选中wsum[i]，在wsum[]中找第一个>rnd的位置
        int idx = upper_bound(begin(wsum), end(wsum), rnd) - begin(wsum);
        auto rect = rects[idx];
        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];
        return {x, y};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
