//
//  ugly-number
//  https://leetcode.com/problems/ugly-number/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        const vector<int> factors = {2, 3, 5};
        for (auto factor : factors) {
            while (num % factor == 0) {
                num /= factor;
            }
        }
        return num == 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isUgly(30);
    
    return 0;
}
