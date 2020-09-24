//
//  guess-number-higher-or-lower
//  https://leetcode.com/problems/guess-number-higher-or-lower/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, u = n;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (guess(mid) <= 0) { // guess()的[1 1 0 -1 -1] 变成返回 [0 0 1 1 1]
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
