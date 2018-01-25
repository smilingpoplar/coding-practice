//
//  first-missing-positive
//  https://leetcode.com/problems/first-missing-positive/
//
//  Created by smilingpoplar on 15/5/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 桶排序，准备N个桶来放数字[1,n]，第i个桶放数字i+1（索引从0开始）(0<=i<=N-1)，即把数字j放到第j-1个桶中(1<=j<=N)
        const int N = (int)nums.size();
        for (int i = 0; i < N; i++) {
            while (nums[i] != i + 1 && 1 <= nums[i] && nums[i] <= N && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]); // 把数字j放到第j-1个桶中
            }
        }
        // first missing
        for (int i = 0; i < N; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        
        return N + 1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1};
    
    Solution solution;
    cout << solution.firstMissingPositive(nums);
    
    return 0;
}
