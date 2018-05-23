//
//  find-the-duplicate-number
//  https://leetcode.com/problems/find-the-duplicate-number/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 把nums[i]看做链表的next指针：i=>nums[i]=>nums[nums[i]]=>...
        // 这题变成找链表环的入口点，快慢指针。由鸽笼原理，一定有环
        int fast = 0, slow = 0;
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) break;
        }
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];    
        }
        return fast;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
