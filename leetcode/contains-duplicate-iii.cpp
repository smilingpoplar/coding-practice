//
//  contains-duplicate-iii
//  https://leetcode.com/problems/contains-duplicate-iii/
//
//  Created by smilingpoplar on 15/6/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        set<long> win; // 总共k+1个元素，win中保存前k个元素以跟当前元素比较，保证窗口长度<=k
        for (int i = 0; i < nums.size(); i++) {
            // win中是否存在x，使nums[i]-x<=t且x-nums[i]<=t，nums[i]-t<=x<=nums[i]+t
            // 只要找>=nums[i]-t的数，看它是否满足<=nums[i]+t
            auto it = win.lower_bound((long)nums[i] - t);
            if (it != win.end() && *it <= (long)nums[i] + t) return true;
            
            win.insert(nums[i]);
            // 保证窗口长度<=k，有效范围[left,i]，i-left+1<=k，left>=i-k+1
            if (win.size() > k) win.erase(nums[i - k]); // 删除超出left的

        }
        return false;
    }
};

/*
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        unordered_map<long, long> buckets; // idx=>num
        // 总共k+1个元素，buckets中保存前k个元素以跟当前元素比较，保证buckets.size()<=k
        for (int i = 0; i < nums.size(); i++) {            
            auto idx = bucketIndex(nums[i], t);
            // 重复发生在自己桶中
            if (buckets.find(idx) != buckets.end()) return true;
            // 重复发生在左右相邻两桶
            if (buckets.find(idx - 1) != buckets.end() && nums[i] - buckets[idx - 1] <= t) return true;
            if (buckets.find(idx + 1) != buckets.end() && buckets[idx + 1] - nums[i] <= t) return true;

            buckets[idx] = nums[i];
            // 保证buckets.size()<=k，有效范围[left,i]，i-left+1<=k，left>=i-k+1
            if (buckets.size() > k) buckets.erase(bucketIndex(nums[i - k], t)); // 删除超出left的
        }
        return false;
    }
    
    // |x-y|<=t有[0..t]个值，桶长t+1能使落在一个桶中的值肯定重复
    long bucketIndex(long num, long t) {
        return (num - INT_MIN) / (t + 1);
    }
};
 */

int main(int argc, const char * argv[]) {
    vector<int> nums = {0, INT_MAX};
    Solution solution;
    cout << solution.containsNearbyAlmostDuplicate(nums, 1, INT_MAX);
    
    return 0;
}
