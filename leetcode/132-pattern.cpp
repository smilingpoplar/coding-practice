//
//  132-pattern
//  https://leetcode.com/problems/132-pattern/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 132模式：顺序三个数a1、a2、a3，a1<a3<a2。
        // 对于第二个数a2，在右边找小于它的最大数rMax，再看左边是否有数<rMax。
        // 某数右边小于它的最大数 <=等价于=> 从右往左找"下一个更大的数"时最后的弹出数
        const int N = nums.size();
        int rMax = INT_MIN;
        stack<int> stk;
        for (int i = N - 1; i >= 0; i--) {
            // 因为rMax将递增，<rMax判断条件将变宽，
            // 即使nums[i]左边有数<rMax，这次没返回以后也会返回
            if (nums[i] < rMax) return true;

            while (!stk.empty() && nums[i] > stk.top()) {
                rMax = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> nums = {3, 1, 4, 2};
    cout << find132pattern(nums);
    return 0;
}
