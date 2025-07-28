//
//  median-of-two-sorted-arrays
//  https://leetcode.com/problems/median-of-two-sorted-arrays/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        const int M = a.size(), N = b.size();
        double median1 = findKthSmallest((M + N + 1) / 2, a, 0, M, b, 0, N);
        if ((M + N) % 2 == 1) return median1;
        return (median1 + findKthSmallest((M + N) / 2 + 1, a, 0, M, b, 0, N)) * 0.5;
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

/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // a分成a[0..i-1]、a[i..M-1]，b分成b[0..j-1]、b[j..N-1]，
        // 令k=(M+N+1)/2，划分i要满足i+j=k，且a[i-1]<=b[j] && b[j-1]<=a[i]
        // 1.要在a、b的较短数组中搜索划分i
        //  由0<=i<=M（i==M时后半为空），j=k-i => k-M<=j<=k；要使0<=j<=N，需要k-M>=0，k<=N => M<=N
        // 2.最终M+N为奇数时，lMax=max(a[i-1],b[j-1])为中位数；
        //  M+N为偶数时，rMin=min(a[i],b[j])，(lMax+rMin)/2为中位数
        const int M = a.size(), N = b.size();
        if (M > N) return findMedianSortedArrays(b, a);

        const int k = (M + N + 1) / 2;
        int lo = 0, hi = M;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;  // 划分点i
            int j = k - i;
            int la = (i > 0) ? a[i - 1] : INT_MIN;
            int lb = (j > 0) ? b[j - 1] : INT_MIN;
            int ra = (i < M) ? a[i] : INT_MAX;
            int rb = (j < N) ? b[j] : INT_MAX;

            if (la > rb) {  // 划分点i太靠右了，要往左移，排除划分点[i..]
                hi = i - 1;
            } else if (lb > ra) {
                lo = i + 1;
            } else {  // 有效的划分
                int lMax = max(la, lb);
                if ((M + N) % 2 == 1) return lMax;
                int rMin = min(ra, rb);
                return (lMax + rMin) * 0.5;
            }
        }
        return -1;
    }
};
*/

/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        const int M = a.size(), N = b.size();
        int k = (M + N + 1) / 2;
        double median = getKthSmallest(k, a, b);
        if ((M + N) % 2 == 1) return median;
        double next = getKthSmallest(k + 1, a, b);
        return (median + next) * 0.5;
    }

    // 在两有序数组中找第k小的数
    double getKthSmallest(int k, vector<int>& a, vector<int>& b) {
        if (a.empty()) return b[k-1];
        if (b.empty()) return a[k-1];
        // 二分搜索，在值范围[min(a[0],b[0])..max(a[M-1],b[N-1])]内猜
        int l = min(a[0], b[0]), u = max(a.back(), b.back());
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (enough(mid, a, b, k)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    // ”a和b中<=value的个数“count>=k
    bool enough(int value, vector<int>& a, vector<int> &b, int k) {
        int count = 0;
        count += upper_bound(a.begin(), a.end(), value) - a.begin();
        count += upper_bound(b.begin(), b.end(), value) - b.begin();
        return count >= k;
    }
};
*/

int main(int argc, const char* argv[]) {
    vector<int> nums1 = {200};
    vector<int> nums2 = {100, 101, 102, 103, 104, 105};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);

    return 0;
}
