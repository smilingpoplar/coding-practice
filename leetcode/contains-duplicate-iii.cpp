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
        if (t < 0) return false;
        set<long> st; // 把前k个数放入set中
        for (int i = 0; i < nums.size(); i++) {
            // 在st中找x，abs(nums[i]-x)<=t，nums[i]-t<=x<=nums[i]+t
            // 只要找>=nums[i]-t的最小数，看它是否<=nums[i]+t
            auto it = st.lower_bound((long)nums[i] - t);
            if (it != st.end() && *it <= (long)nums[i] + t) return true;
            
            st.insert(nums[i]);
            if (st.size() > k) st.erase(nums[i-k]);
        }
        return false;
    }
};

/*
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (t < 0) return false;
        unordered_map<long, long> buckets; // bucketIdxOfNum=>num
        // buckets保存前k个数的桶，buckets.size()<=k
        for (int i = 0; i < nums.size(); i++) {            
            auto idx = bucketIdx(nums[i], t);
            // 又落在自己桶
            if (buckets.count(idx)) return true;
            // 检查相邻两桶
            if (buckets.count(idx-1) && nums[i] - buckets[idx-1] <= t) return true;
            if (buckets.count(idx+1) && buckets[idx+1] - nums[i] <= t) return true;

            buckets[idx] = nums[i];
            if (buckets.size() > k) buckets.erase(bucketIdx(nums[i-k], t));
        }
        return false;
    }
    
    // |x-y|<=t有[0..t]个值，桶长t+1时落在一个桶中的值肯定重复
    long bucketIdx(long num, long t) {
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
