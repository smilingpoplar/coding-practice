//
//  monotonic-array
//  https://leetcode.com/problems/monotonic-array/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        const int N = A.size();
        int dir = 0;
        for (int i = 0; i + 1 < N; i++) {
            int diff = A[i+1] - A[i];
            if (diff == 0) continue;
            if (dir == 0) dir = diff;
            else if ((dir ^ diff) < 0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
