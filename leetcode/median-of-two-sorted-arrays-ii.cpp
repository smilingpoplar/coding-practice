//
//  median-of-two-sorted-arrays
//  在两个长度相等的排序数组中找到上中位数
//
//  给定两个递增数组arr1和arr2，已知两个数组的长度都为N，求两个数组中所有数的上中位数。
//  上中位数：假设递增序列长度为n，为第n/2个数
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        const int N = arr1.size();  // 上中位数是在合并数组中第N小的数
        int lo = 0, hi = N - 1;
        while (lo < hi) {
            int mid1 = lo + (hi - lo) / 2;
            // 划分出N个元素 arr1[0..mid1]、arr2[0..mid2]，有 mid1+1 + mid2+1 == N
            int mid2 = N - 2 - mid1;
            int a1 = arr1[mid1], a2 = arr2[mid2];
            if (a1 < a2) {
                // 一共划分出N个元素，arr1[mid1]较小，不可能是第N个元素，排除 arr1[0..mid1]
                lo = mid1 + 1;
            } else if (a1 > a2) {
                // N个元素的划分之外的 arr1[mid1+1..]，可以排除
                hi = mid1;
            } else {
                return a1;
            }
        }
        // 合并数组中 lo+x == N-1，x = N-1-lo
        return min(arr1[lo], arr2[N - 1 - lo]);
    }
};
