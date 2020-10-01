//
//  circular-permutation-in-binary-representation
//  https://leetcode.com/problems/circular-permutation-in-binary-representation/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        for (int i = 0; i < 1 << n; i++) {
            ans.push_back(start ^ (i ^ (i >> 1)));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
