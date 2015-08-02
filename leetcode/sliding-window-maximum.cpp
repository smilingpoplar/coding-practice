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
        // sliding window maximum/minimum = monotonic queue
        // 用dequeue保存nums索引，索引i进队列前从队尾不断弹出 对应元素<nums[i]的索引x
        // 因为nums[x]<nums[i]不可能是窗口[i-k+1,i]及后续窗口的最大元素（nums[i]是更好的选择）
        // dequeue始终保存着单调递减序列的索引，队头是当前窗口最大值的索引
        // 参考：https://leetcode.com/discuss/46578/java-o-n-solution-using-deque-with-explanation
        
        vector<int> result;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) result.push_back(nums[dq.front()]);
        }
        return result;
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
