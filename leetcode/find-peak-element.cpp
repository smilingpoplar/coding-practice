//
//  find-peak-element
//  https://leetcode.com/problems/find-peak-element/
//
//  Created by smilingpoplar on 15/5/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        const int N = (int)nums.size();
        // 不变式：nums[i,j]中存在peak值，0<=i<=j<N
        int i = 0;
        int j = N - 1;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] > nums[mid + 1]) {
                // 假设nums[i,mid]中不存在peak值，mid左端的数要一个比一个大，
                // 这样最终nums[i]肯定是peak值，与假设矛盾，故nums[i,mid]中存在peak值
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i; // i==j
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    cout << solution.findPeakElement(nums);
    
    return 0;
}
