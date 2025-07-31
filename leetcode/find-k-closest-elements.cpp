//
//  find-k-closest-elements
//  https://leetcode.com/problems/find-k-closest-elements/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 设要找的子段为 arr[i..i+k-1]，对位置i做二分搜索
        // 比较 arr[i] 和 子段后的arr[i+k]：
        // 若 x - arr[i] > arr[i+k] - x，右移子段起始i
        int lo = 0, hi = (int)arr.size() - k;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return vector<int>(begin(arr) + lo, begin(arr) + lo + k);
    }
};

/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 双指针法
        int i = 0, j = (int)arr.size() - 1;
        while (j - i >= k) {  // 循环结束后 j-i+1 == k
            if (abs(x - arr[i]) <= abs(arr[j] - x)) {
                j--;
            } else {
                i++;
            }
        }

        return vector<int>(begin(arr) + i, begin(arr) + i + k);
    }
};
*/

int main(int argc, const char* argv[]) {
    return 0;
}
