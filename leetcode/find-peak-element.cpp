//
//  find-peak-element
//  https://leetcode.com/problems/find-peak-element/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 找波峰，对应找下一个更小的数
        const int N = nums.size();
        for (int i = 0; i < N - 1; i++) {
            if (nums[i] > nums[i+1]) return i;
        }
        return N - 1;
    }
};
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 只要不断往高处走，就一定有波峰，这是一种单调性
        // 找波峰，找第一个nums[i]>nums[i+1]的位置i
        // i二分搜索的范围是[0..N-2]
        const int N = nums.size();
        int l = -1, u = N - 1;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                u = mid;
            } else {
                l = mid;
            }
        }
        return u;
    }

    // 三种写法都可以
    /*
    int findPeakElement(vector<int>& nums) {
        const int N = nums.size();
        int l = 0, u = N - 2;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] > nums[mid+1]) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    */

    /*
    int findPeakElement(vector<int>& nums) {
        const int N = nums.size();
        int l = 0, u = N - 1; // 前闭后开，l相关的要改
        while (l < u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] > nums[mid+1]) {
                u = mid;
            } else {
                l = mid + 1;
            }
        }
        return u;
    }
    */
};

int main(int argc, const char* argv[]) {
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    cout << solution.findPeakElement(nums);

    return 0;
}
