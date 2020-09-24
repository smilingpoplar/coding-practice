//
//  global-and-local-inversions
//  https://leetcode.com/problems/global-and-local-inversions/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        // 全局逆序数==相邻逆序数，除了相邻、没有逆序，
        // 即max(A[0..i-2])<=A[i]
        int theMax = -1;
        for (int i = 2; i < A.size(); i++) {
            theMax = max(theMax, A[i-2]);
            if (theMax > A[i]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
