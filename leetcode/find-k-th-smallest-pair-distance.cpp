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
        // 距离x的取值范围[0, max(nums)-min(nums)]
        sort(nums.begin(), nums.end());
        int l = 0, u = nums[nums.size() - 1] - nums[0];
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (enough(mid, nums, k)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    // 找第k小的数，当猜的数不断变大时、二分搜索要输出[0,0,...,0,1,1,...]，因此要猜数是否>=第k小的数。
    // 条件式enough(x)中要看x是第几小的数，即统计出<=x的个数count，判断是否count>=k。
    bool enough(int x, vector<int> &nums, int k) {
        int count = 0;
        for (int j = 1; j < nums.size(); j++) {
            int i = 0;
            while (nums[j] - nums[i] > x) i++;
            // 现在 nums[j] - nums[i] <= x
            count += j - i; // [i..j)
        }
        return count >= k;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
