//
//  length-of-subarray-with-positive-product
//  https://leetcode.com/problems/length-of-subarray-with-positive-product/
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // 设pos[i]表示以nums[i]开头的nums[i..]的正乘积最大长，
        // neg[i]表示以nums[i]开头的nums[i..]的负乘积最大长
        // nums[i] > 0 时，pos[i] = pos[i+1] + 1
        //                neg[i] = neg[i+1] > 0 ? neg[i+1] + 1 : 0
        //         < 0 时，pos[i] = neg[i+1] > 0 ? neg[i+1] + 1 : 0
        //                neg[i] = pos[i+1] + 1
        //        == 0 时，pos[i] = neg[i] = 0
        const int N = nums.size();
        vector<int> pos(N + 1, 0), neg(N + 1, 0);
        int ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (nums[i] > 0) {
                pos[i] = pos[i + 1] + 1;
                neg[i] = neg[i + 1] > 0 ? neg[i + 1] + 1 : 0;
            } else if (nums[i] < 0) {
                pos[i] = neg[i + 1] > 0 ? neg[i + 1] + 1 : 0;
                neg[i] = pos[i + 1] + 1;
            } else {
                pos[i] = neg[i] = 0;
            }
            ans = max(ans, pos[i]);
        }
        return ans;
    }
};