//
//  range-sum-of-sorted-subarray-sums
//  https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& A, int n, int left, int right) {
        // 从A[i]开始的子段和A[i..]构成N个有序数组，求其中的第[left,right]大的和
        const int MOD = 1e9 + 7;
        using arr2 = array<int, 2>; // {sum,idx}
        priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({A[i], i});
        }
        
        int cnt = 0, ans = 0;
        while (!pq.empty()) {
            auto [sum, idx] = pq.top();  pq.pop();
            cnt++;
            if (cnt >= left) {
                ans = (ans + sum) % MOD;
                if (cnt == right) break;
            }
            
            if (idx + 1 < n) {
                sum += A[idx + 1];
                pq.push({sum, idx + 1});
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
