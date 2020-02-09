//
//  sum-of-mutated-array-closest-to-target
//  https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        const int N = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> presum(N + 1, 0);
        int maxval = INT_MIN;
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + arr[i];
            maxval = max(maxval, arr[i]);
        }
        
        int l = 0, u = maxval + 1;
        while (l + 1 < u) {
            int m = l + (u - l) / 2;
            if (getSum(arr, m, presum) >= target) {
                u = m;
            } else {
                l = m;
            }
        }
        // u和u-1作为候选
        int diff1 = abs(getSum(arr, u, presum) - target);
        int diff2 = abs(getSum(arr, u-1, presum) - target);
        return diff1 < diff2 ? u : u-1;
    }
    
    int getSum(vector<int>& arr, int num, const vector<int> &presum) {
        int idx = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
        // [0..idx)为原数，[idx..N)变为num
        int sum = presum[idx] + (arr.size() - idx) * num;
        return sum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
