//
//  smallest-range-i
//  https://leetcode.com/problems/smallest-range-i/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int theMin = A[0], theMax = A[0];
        for (int a : A) {
            theMin = min(theMin, a);
            theMax = max(theMax, a);
        }
        return max(0, theMax - theMin - 2 * K);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
