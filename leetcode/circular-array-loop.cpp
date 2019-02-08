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
            if (nums[i] == 0) continue; // 无循环路径上的点已设为0

            // 从i出发是否构成循环路径
            int fast = i, slow = i;
            while (true) {
                int next = getNext(fast, nums);
                if (nums[i] * nums[next] < 0) break; // 要求循环方向不变
                fast = next, next = getNext(fast, nums);
                if (nums[i] * nums[next] < 0) break;
                fast = next;
                
                slow = getNext(slow, nums);
                if (fast == slow) { // 有环
                    if (fast == getNext(fast, nums)) break; // 排除单数成环
                    return true;
                }
            }
            
            // 至此从i出发够不成循环，将路径上的点都设为0
            int dir = nums[i], idx = i;
            while (dir * nums[idx] > 0) {
                int next = getNext(idx, nums);
                nums[idx] = 0;
                idx = next;
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
