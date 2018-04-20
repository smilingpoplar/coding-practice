//
//  sliding-window-maximum
//  https://leetcode.com/problems/sliding-window-maximum/
//
//  Created by smilingpoplar on 15/8/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 双端队列deque保存当前窗口中最大值的下标，当前窗口指右端为i的窗口nums[i-k+1..i]
        // 当前数>队尾时，队尾不可能是最大值，队尾可弹出。
        // 当前数>队尾 <=> 找波谷 <=> deque对应波谷左侧、是递减序列 <=> 队头是当前窗口的最大值
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && i - dq.front() + 1 > k) dq.pop_front();
            while (!dq.empty() && nums[i] > nums[dq.back()]) 
                dq.pop_back();
            dq.push_back(i);
            if (i - k + 1 >= 0) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution solution;
    auto result = solution.maxSlidingWindow(nums, k);
    for (auto num : result) {
        cout << num << " ";
    }
    
    return 0;
}
