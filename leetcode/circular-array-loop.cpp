//
//  circular-array-loop
//  https://leetcode.com/problems/circular-array-loop/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        const int N = nums.size();
        // 快慢指针找循环
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0) continue; // 非循环路径上的数将标记为0
            
            int fast = i, slow = i;
            while (true) {
                // fast移动两步，slow移动一步
                int next = getNext(fast, nums);
                if (nums[i] * nums[next] < 0) break; // 循环方向不能变
                fast = next, next = getNext(fast, nums);
                if (nums[i] * nums[next] < 0) break; // 循环方向不能变
                fast = next, next = getNext(fast, nums);
                
                slow = getNext(slow, nums);
                if (fast == slow) { // 有环
                    if (fast == next) break; // 但单个数不算循环
                    return true;
                }
            }
            
            // 从i出发的非循环路径上的数都标记为0
            int val = nums[i];
            slow = i;
            while (val * nums[slow] > 0) {
                int next = getNext(slow, nums);
                nums[slow] = 0;
                slow = next;
            }
        }
        return false;
    }
    
    int getNext(int idx, vector<int> &nums) {
        const int N = nums.size();
        int ans = (idx + nums[idx]) % N;
        if (ans < 0) ans += N;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
