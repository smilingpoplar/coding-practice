//
//  water-and-jug-problem
//  https://leetcode.com/problems/water-and-jug-problem/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    
    int gcd(int a, int b) {
        while (b) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
