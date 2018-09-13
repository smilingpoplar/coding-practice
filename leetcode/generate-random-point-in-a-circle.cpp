//
//  generate-random-point-in-a-circle
//  https://leetcode.com/problems/generate-random-point-in-a-circle/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        srand(NULL);
    }
    
    vector<double> randPoint() {
        // 半径sqrt(uniform)分布，则圆内uniform分布
        double r = sqrt(randf()) * radius;
        double radian = randf() * 2 * 3.14;
        double x = x_center + r * cos(radian);
        double y = y_center + r * sin(radian);
        return {x, y};
    }
    
    double randf() {
        return (double)rand() / RAND_MAX;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
