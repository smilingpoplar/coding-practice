//
//  non-decreasing-array
//  https://leetcode.com/problems/non-decreasing-array/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // 贪婪法。找到违反<=关系的x[i]>x[i+1]，优先改小x[i]：x[i]=x[i+1]。
        // （后面是否满足<=待后面循环去检查，前面满足要还需x[i-1]<=x[i+1]）
        // 无法改小时改大x[i+1]：x[i+1]=x[i]。
        int cnt = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] <= nums[i+1]) continue;
            if (cnt++ > 0) return false;
            // 优先改小x[i]
            if (i-1 < 0 || nums[i-1] <= nums[i+1]) {
                nums[i] = nums[i+1];
            } else {
                nums[i+1] = nums[i];
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
