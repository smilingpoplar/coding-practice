//
//  max-consecutive-ones-iii
//  https://leetcode.com/problems/max-consecutive-ones-iii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        const int N = A.size();
        int zeroCnt = 0, ans = INT_MIN;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            if (A[hi] == 0) zeroCnt++;
            while (zeroCnt > K) {
                if (A[lo++] == 0) zeroCnt--;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
