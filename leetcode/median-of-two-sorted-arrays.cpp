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
        // 数组a分成a[0..i-1]、a[i..M-1]两部分，数组b分成b[0..j-1]、b[j..N-1]两部分，
        // 令k=(M+N+1)/2，划分i要满足i+j=k，且a[i-1]<=b[j] && b[j-1]<=a[i]
        // 1.要在a、b的较短数组中搜索划分i
        //  由0<=i<=M（i==M时后半为空），j=k-i => k-M<=j<=k；要使0<=j<=N，需要k-M>=0，k<=N => M<=N
        // 2.最终M+N为奇数时，lMax=max(a[i-1],b[j-1])为中位数
        // M+N为偶数时，(lMax+rMin)/2为中位数，rMin=min(a[i],b[j])
        const int M = a.size(), N = b.size();
        if (M > N) return findMedianSortedArrays(b, a);
        
        const int k = (M + N + 1) / 2;
        int l = 0, u = M;
        while (l <= u) {
            int i = l + (u - l) / 2, j = k - i;
            if (i > 0 && j < N && a[i-1] > b[j]) { // 需要a[i-1]<=b[j]，现在i太大了，要在左半找
                u = i - 1; 
            } else if (j > 0 && i < M && b[j-1] > a[i]) { // 需要b[j-1]<=a[i]，现在i太小了，要在右半找
                l = i + 1;
            } else { // 有效的划分i
                int lMax = INT_MIN;
                if (i > 0) lMax = max(lMax, a[i-1]);
                if (j > 0) lMax = max(lMax, b[j-1]);
                if ((M + N) % 2 == 1) return lMax;

                int rMin = INT_MAX;
                if (i < M) rMin = min(rMin, a[i]);
                if (j < N) rMin = min(rMin, b[j]);
                return (lMax + rMin) * 0.5;
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
