//
//  max-consecutive-ones-iii
//  https://leetcode.com/problems/max-consecutive-ones-iii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        // 滑动窗口中至多k个0，用队列保存各0的下标
        // 有效窗口：zeroIdx.size() <= k
        int ans = 0;
        queue<int> zeroIdx;
        for (int lo = 0, hi = 0; hi < A.size(); hi++) {
            if (A[hi] == 0) zeroIdx.push(hi);

            while (zeroIdx.size() > K) {
                lo = zeroIdx.front() + 1;
                zeroIdx.pop();
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
