//
//  asteroid-collision
//  https://leetcode.com/problems/asteroid-collision/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int i = 0; i < asteroids.size(); i++) {
            if (stk.empty() || stk.back() < 0 || asteroids[i] > 0) {
                stk.push_back(asteroids[i]);
            } else {
                if (stk.back() == -asteroids[i]) {
                    stk.pop_back();
                } else if (stk.back() < -asteroids[i]) {
                    stk.pop_back();
                    i--; // 继续看i
                }
            }
        }
        return stk;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
