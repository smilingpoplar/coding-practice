//
//  find-in-mountain-array
//  https://leetcode.com/problems/find-in-mountain-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // 二分搜索，先找峰值，再分别找左右半数组
        // 找第一个A[m]>A[m+1]的位置m，m在[1..N-2]
        const int N = mountainArr.length();
        int l = 0, u = N - 1;
        while (l + 1 < u) {
            int m = l + (u - l) / 2;
            if (mountainArr.get(m) > mountainArr.get(m + 1)) {
                u = m;
            } else {
                l = m;
            }
        }
        // u是波峰
        int ans = binarySsearch(target, mountainArr, 0, u, true);
        if (ans != -1) return ans;
        return binarySsearch(target, mountainArr, u, N - 1, false);
    }

    int binarySsearch(int target, MountainArray &mountainArr, 
                    int lower, int upper, bool asc) {
        int l = lower, u = upper;
        while (l <= u) {
            int m = l + (u - l) / 2;
            int val = mountainArr.get(m);
            if (target == val) return m;
            if ((target < val) == asc) {
                u = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
