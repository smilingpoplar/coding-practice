//
//  house-robber-ii
//  https://leetcode.com/problems/house-robber-ii/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int N = (int)nums.size();
        if (N == 1) return nums[0];
        // 因为首尾循环，首尾元素不能同时选择，根据不选尾元素还是不选首元素，
        // 分成无循环的两个子问题rob(nums,0,n-2)和rob(nums,1,n-1)
        return max(rob(nums, 0, N - 2), rob(nums, 1, N - 1));
    }
private:
    // rob nums[from,to]
    int rob(const vector<int> &nums, int from, int to) {
        // 设f(i)表示抢了nums[from,i]后的最大值，from<=i<=to，
        // f(i) = max( nums[i] + f(i-2), f(i-1) )，设i<from时f(i)==0
        // 看递推式的当前项只依赖于前两项，前两项分别用prev2和prev1表示
        int prev2 = 0, prev1 = 0;
        int current = 0;
        for (int i = from; i <= to; ++i) {
            current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,20,100,2};
    Solution solution;
    cout << solution.rob(nums);
    
    return 0;
}