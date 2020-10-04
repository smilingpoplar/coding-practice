//
//  k-concatenation-maximum-sum
//  https://leetcode.com/problems/k-concatenation-maximum-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // 最大子段和只有三种取值：
        //  1. 在arr中间  2. 在两数组尾首arr[..N-1]+arr[0..]
        //  3. 在两数组尾首处插入(k-2)个arr[]
        long maxendinghere = 0, maxsofar = 0;
        for (int i = 0; i < min(k, 2); i++) { // 前两种情况
            for (int a : arr) {
                maxendinghere = max(maxendinghere + a, 0L);
                maxsofar = max(maxsofar, maxendinghere);
            }
        }
        
        long sum = accumulate(begin(arr), end(arr), 0);
        const int MOD = 1e9 + 7;
        return max(maxsofar, maxsofar + (k - 2) * sum) % MOD;               
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
