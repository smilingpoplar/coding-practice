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
        
        int out = k;
        for (int in = k; in < N; in++) {
            if (nums[in] != nums[out-k]) {
                nums[out++] = nums[in];
            }
        }
        return out;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    cout << solution.removeDuplicates(nums);
    
    return 0;
}
