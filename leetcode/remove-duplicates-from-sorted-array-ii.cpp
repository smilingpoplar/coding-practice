//
//  remove-duplicates-from-sorted-array-ii
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size(), k = 2;
        if (N <= k) return N;

        int i = k, o = k;
        while (i < N) {
            // 若 nums[i] != nums[o-k]，则最多 nums[o-k+1..o-1] k-1个数是nums[i]
            // 若 nums[i] == nums[o-k]，则 nums[o-k..o-1] k个数一定都是nums[i]，因为数组有序
            if (nums[i] != nums[o - k]) {
                nums[o++] = nums[i];
            }
            i++;
        }
        return o;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution solution;
    cout << solution.removeDuplicates(nums);

    return 0;
}
