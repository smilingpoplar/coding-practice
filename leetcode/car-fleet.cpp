//
//  car-fleet
//  https://leetcode.com/problems/car-fleet/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int N = position.size();
        vector<pair<int, double>> cars; // dist => 什么时间到达
        for (int i = 0; i < N; i++) {
            cars.push_back({ target - position[i], double(target - position[i]) / speed[i] });
        }
        sort(cars.begin(), cars.end());
        
        int ans = 0;
        double time = 0;
        for (int i = 0; i < N; i++) {
            if (cars[i].second > time) { // 更晚到达的成为新fleet头
                ans++;
                time = cars[i].second;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
