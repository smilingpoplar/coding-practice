//
//  median-of-two-sorted-arrays
//  https://leetcode.com/problems/median-of-two-sorted-arrays/
//
//  Created by smilingpoplar on 15/6/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // 数组a分成a1[0..i-1]、a2[i..M-1]两部分，数组b分成b1[0..j-1]、b2[j..N-1]两部分。
        // 把a1和b1放一起构成整体的left部分，设k=len(left)=i+j，为使max(left)是第k小的数，
        // 只需max(left)<=min(right)，即a[i-1]<=b[j] && b[j-1]<=a[i] (1)。
        // 现在要找中位数（或两中位数的第一个），令k=(M+N+1)/2，二分搜索0<=i<=M，找满足(1)式的i。
        // 由0<=i<=M，j=k-i，k-M<=j<=k；要使0<=j<=N，需要k-M>=0、k<=N，M<=N，即在短数组中搜索i。
        const int M = a.size(), N = b.size();
        if (M > N) return findMedianSortedArrays(b, a);
        
        int k = (M + N + 1) / 2;
        int l = 0, u = M;
        while (l <= u) {
            int i = l + (u - l) / 2;
            int j = k - i;
            if (i > 0 && a[i-1] > b[j]) {
                // 需要a[i-1]<=b[j]，现在i太大了，要在左半找
                u = i - 1; 
            } else if (i < M && b[j-1] > a[i]) {
                // 需要b[j-1]<=a[i]，现在i太小了，要在右半找
                l = i + 1;
            } else { // 找到满足(1)式的i
                int leftMax = INT_MIN;
                if (i > 0) leftMax = max(leftMax, a[i-1]);
                if (j > 0) leftMax = max(leftMax, b[j-1]);
                if ((M + N) % 2 == 1) return leftMax;

                int rightMin = INT_MAX;
                if (i < M) rightMin = min(rightMin, a[i]);
                if (j < N) rightMin = min(rightMin, b[j]);
                return (leftMax + rightMin) * 0.5;
            }
        }
        return -1;
    }
};

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

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {200};
    vector<int> nums2 = {100,101,102,103,104,105};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    
    return 0;
}
