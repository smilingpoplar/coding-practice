//
//  global-and-local-inversions
//  https://leetcode.com/problems/global-and-local-inversions/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        // 全局逆序数==相邻逆序数，除了相邻、没有逆序，
        // 即对所有j、0<=i<=j-2，应有A[i]<=A[j]，max(A[0..j-2])<=A[j]
        int theMax = -1;
        for (int j = 2; j < A.size(); j++) {
            theMax = max(theMax, A[j-2]);
            if (theMax > A[j]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
