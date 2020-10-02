//
//  longest-mountain-in-array
//  https://leetcode.com/problems/longest-mountain-in-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans = 0;
        int up = 0, down = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) {
                if (down > 0) up = down = 0;
                up++;
            } else if (A[i] < A[i-1]) {
                down++;
            } else {
                up = down = 0;
            }
            
            if (up > 0 && down > 0) ans = max(ans, 1 + up + down); // 1来自A[0]
        }
        return ans;
    }
};

/*
int longestMountain(vector<int>& A) {
    const int N = A.size();
    vector<int> inc(N), dec(N);
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i-1]) 
            inc[i] = inc[i-1] + 1;
    }
    for (int i = N - 2; i >= 0; i--) {
        if (A[i] > A[i+1]) 
            dec[i] = dec[i+1] + 1;
    }
    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if (inc[i] && dec[i]) 
            ans = max(ans, inc[i] + dec[i] + 1);
    }
    return ans;
}
*/

int main(int argc, const char * argv[]) {
    return 0;
}
