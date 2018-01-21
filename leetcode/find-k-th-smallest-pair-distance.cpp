//
//  find-k-th-smallest-pair-distance
//  https://leetcode.com/problems/find-k-th-smallest-pair-distance/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // enough(x)表示x至少是第k小的距离
        // 距离x的取值范围[0, max(nums)-min(nums)]
        sort(nums.begin(), nums.end());
        int l = -1, u = nums[nums.size() - 1] - nums[0] + 1;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (enough(mid, nums, k)) {
                u = mid;
            } else {
                l = mid;
            }
        }
        return u;
    }
    
    bool enough(int dist, vector<int> &nums, int k) {
        int count = 0;
        for (int j = 0; j < nums.size(); ++j) {
            int i = 0;
            while (nums[j] - nums[i] > dist) ++i;
            // 现在 nums[j] - nums[i] <= dist
            count += j - i; // 又多了些比dist小的距离
        }
        return count >= k;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
