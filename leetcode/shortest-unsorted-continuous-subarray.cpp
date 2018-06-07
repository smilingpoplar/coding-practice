//
//  shortest-unsorted-continuous-subarray
//  https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        int maxL = INT_MIN, minR = INT_MAX;
        int l = 0, r = -1;
        for (int i = 0, j = N - 1; i < N; i++, j--) {
            maxL = max(maxL, nums[i]);
            if (nums[i] != maxL) r = i;
            
            minR = min(minR, nums[j]);
            if (nums[j] != minR) l = j;
        }
        return r - l + 1;
    }
};
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        // 先从两端向内找到第一个无序的位置（靠内）
        int i = 0, j = N - 1;
        while (i < N - 1 && nums[i] <= nums[i+1])
            i++;
        while (j > 0 && nums[j-1] <= nums[j])
            j--;
        if (i >= j) return 0;
        // 在nums[i..j]中找到minNum和maxNum
        int minNum = INT_MAX, maxNum = INT_MIN;
        for (int k = i; k <= j; k++) {
            minNum = min(minNum, nums[k]);
            maxNum = max(maxNum, nums[k]);
        }
        // 根据nums[i-1]<=minNum、nums[j+1]>=maxNum向外扩展
        while (i >= 1 && nums[i-1] > minNum)
            i--;
        while (j < N - 1 && nums[j+1] < maxNum)
            j++;
        
        return j - i + 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
