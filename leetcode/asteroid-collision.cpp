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
        vector<int> stack;
        for (int i = 0; i < asteroids.size(); i++) {
            if (stack.empty() || stack.back() < 0 || asteroids[i] > 0) {
                stack.push_back(asteroids[i]);
            } else {
                if (stack.back() == -asteroids[i]) {
                    stack.pop_back();
                } else if (stack.back() < -asteroids[i]) {              
                    stack.pop_back();
                    --i;
                }
            }
        }
        return stack;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
