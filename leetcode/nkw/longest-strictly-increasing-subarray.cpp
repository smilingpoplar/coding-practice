//
//  longest-strictly-increasing-subarray
//  NC155 最长严格上升子数组(一)
//  给定一个长度为n的正整数数组nums，可以任意改变数组的其中一个元素，改变的元素范围也在[1,100000]之内，然后返回nums的最长"严格上升"子数组的长度。
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArrayLengthTwo(vector<int>& nums) {
        // 设l[i]表示以nums[i]结尾的nums[0..i]的最长严格上升子数组长，
        // l[i] = (nums[i-1] < nums[i]) ? l[i-1] + 1 : 1;
        // r[i]表示以nums[i]开头的nums[i..]的最长严格上升子数组长，
        // r[i] = (nums[i] < nums[i+1]) ? r[i+1] + 1 : 1;
        const int N = nums.size();
        const int MIN_VAL = 1, MAX_VAL = 1e5;
        vector<int> l(N, 1);
        int ans = 1;
        for (int i = 1; i < N; i++) {
            if (nums[i] > nums[i - 1]) {
                l[i] = l[i - 1] + 1;
            }
            if (nums[i - 1] < MAX_VAL) {  // 若修改nums[i]
                ans = max(ans, l[i - 1] + 1);
            }
        }
        vector<int> r(N, 1);
        for (int i = N - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                r[i] = r[i + 1] + 1;
            }
            if (nums[i + 1] > MIN_VAL) {  // 若修改nums[i]
                ans = max(ans, r[i + 1] + 1);
            }
        }

        for (int i = 1; i < N - 1; i++) {
            if (nums[i - 1] + 1 < nums[i + 1]) {  // 若修改nums[i]
                ans = max(ans, l[i - 1] + 1 + r[i + 1]);
            }
        }
        return ans;
    }
};
