//
//  arranging-coins
//  https://leetcode.com/problems/arranging-coins/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long k = 0;
        while (k * (k + 1) / 2 <= n) k++;
        return k - 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
