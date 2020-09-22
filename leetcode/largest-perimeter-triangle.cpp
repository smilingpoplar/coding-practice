//
//  largest-perimeter-triangle
//  https://leetcode.com/problems/largest-perimeter-triangle/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        const int N = A.size();
        for (int i = N - 3; i >= 0; i--) {
            if (A[i] + A[i+1] > A[i+2]) 
                return A[i] + A[i+1] + A[i+2];
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
