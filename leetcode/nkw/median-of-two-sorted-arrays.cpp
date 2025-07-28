//
//  median-of-two-sorted-arrays
//  NC36 在两个长度相等的排序数组中找到上中位数
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
        const int N = arr1.size();
        int k = N;  // 上中位数是在合并数组中第N小的数
        return findKthSmallest(k, arr1, 0, N, arr2, 0, N);
    }

    // 在arr1[star1..end1)和arr2[start2..end2)中找第k小的数
    int findKthSmallest(int k, const vector<int>& arr1, int start1, int end1,
                        const vector<int>& arr2, int start2, int end2) {
        int len1 = end1 - start1, len2 = end2 - start2;
        if (len1 > len2) return findKthSmallest(k, arr2, start2, end2, arr1, start1, end1);
        if (len1 == 0) return arr2[start2 + k - 1];
        if (k == 1) return min(arr1[start1], arr2[start2]);

        // 划分出k个元素: arr1[start1..mid1]、arr2[start2..mid1]
        int k1 = min(k / 2, end1 - start1);  // A的划分位置
        int k2 = k - k1;
        int mid1 = start1 + k1 - 1;
        int mid2 = start2 + k2 - 1;

        if (arr1[mid1] < arr2[mid2]) {
            // 排除a[start1..mid1]
            return findKthSmallest(k - k1, arr1, mid1 + 1, end1, arr2, start2, end2);
        } else if (arr1[mid1] > arr2[mid2]) {
            // 排除b[start2..mid2]
            return findKthSmallest(k - k2, arr1, start1, end1, arr2, mid2 + 1, end2);
        } else {
            return arr1[mid1];
        }
        return -1;  // 不会到达这里
    }
};
