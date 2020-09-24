//
//  k-th-smallest-prime-fraction
//  https://leetcode.com/problems/k-th-smallest-prime-fraction/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        // 就是在行列有序的矩阵中找第K小的数
        // 1/2  1/3  1/5
        //      2/3  2/5
        //           3/5
        
        // 最小堆里存行列坐标，第一行先进队列
        const int N = A.size();
        auto cmp = [&A](vector<int> &a, vector<int> &b) {
            return A[a[0]] * A[b[1]] > A[b[0]] * A[a[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 1; i < N; i++) pq.push({0, i});

        while (--K) { // (0,K)，弹出K-1个数
            auto idx = pq.top(); pq.pop();
            if (idx[0] + 1 < idx[1]) pq.push({idx[0] + 1, idx[1]});
        }
        auto idx = pq.top(); pq.pop();
        return {A[idx[0]], A[idx[1]]};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
