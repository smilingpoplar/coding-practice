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
        // 数组a在任意位置i分成a1[0..i-1]、a2[i..M-1]两部分，数组b在任意位置j分成b1[0..j-1]、b2[j..N-1]两部分。
        // 把a1和b1放一起构成整体的left部分，a2和b2放一起构成整体的right部分。设k=len(left)=i+j，
        // 则要使max(left)第k大的数，只需max(left)<=min(right)，即a[i-1]<=b[j]且b[j-1]<=a[i] (1)。
        // 现在要找中位数（或两中位数的第一个），k=(M+N+1)/2。综上，二分搜索0<=i<=M、j=k-i，验证(1)式。
        // 不妨使M<=N，则M<=中位数k<=N。由0<=i<=min(k,M)=M，j=k-i，得0<=k-M<=j<=k<=N，对应j值都合法。
        const int M = a.size();
        const int N = b.size();
        if (M > N) return findMedianSortedArrays(b, a);
        
        int k = (M + N + 1) / 2;
        int l = 0, u = M;
        while (l <= u) {
            int i = l + (u - l) / 2;
            int j = k - i;
            if (i > 0 && a[i-1] > b[j]) {
                // 需要a[i-1]<=b[j]，现在i太大了，要在左半边找
                u = i - 1; 
            } else if (i < M && b[j-1] > a[i]) { // i<M时 j>0
                // 需要b[j-1]<=a[i]，现在i太小了，要在右半边找
                l = i + 1;
            } else { // 肯定能找到
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
        return INT_MIN;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {200};
    vector<int> nums2 = {100,101,102,103,104,105};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    
    return 0;
}
