//
//  3sum-closest
//  https://leetcode.com/problems/3sum-closest/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int N = nums.size();
        if (N < 3) return INT_MAX;
        sort(begin(nums), end(nums));  // 先排序再两指针

        int minDist = INT_MAX, ans;
        for (int i = 0; i < N - 2; i++) {
            int j = i + 1, k = N - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int dist = abs(sum - target);
                if (dist < minDist) {
                    minDist = dist;
                    ans = sum;
                }

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution solution;
    cout << solution.threeSumClosest(nums, target);

    return 0;
}
