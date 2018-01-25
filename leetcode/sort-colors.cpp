//
//  sort-colors
//  https://leetcode.com/problems/sort-colors/
//
//  Created by smilingpoplar on 15/5/11.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 一遍扫描，把0都堆到[0,i0)，把2都堆到(i2,N-1]
        // 不变式：
        // | == 0 | == 1 |  ?  | == 2 |
        // [0     [i0    [i  i2]   N-1]
        const int N = (int)nums.size();
        int i0 = 0;
        int i2 = N - 1;
        int i = 0;
        while (i <= i2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[i0]);
                ++i0;
                ++i; // 换过来的是1
            } else if (nums[i] == 2) {
                swap(nums[i], nums[i2]);
                --i2;
                // 换过来的是?，不能++i
            } else {
                ++i;
            }
        }
    }
    
    /* 计数排序
    void sortColors(vector<int>& nums) {
        int count[3] = { 0 };
        for (auto num : nums) {
            ++count[num];
        }
        for (int i = 0, index = 0; i < 3; i++) {
            for (int j = 0; j < count[i]; j++) {
                nums[index] = i;
                ++index;
            }
        }
    }
    */
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 0, 2, 1};
    Solution solution;
    solution.sortColors(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    
    return 0;
}
