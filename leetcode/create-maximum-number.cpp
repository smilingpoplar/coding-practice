//
//  create-maximum-number
//  https://leetcode.com/problems/create-maximum-number/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // 一个数组取i个数以组成最大数，另一个数组取k-i个数以组成最大数，将两个单数组的最大数合并成两数组的最大数。
        // 0<=i<=M, 0<=k-i<=N => 0<=i<=M, k-n<=i<=k => max(0,k-n)<=i<=min(k,M)
        vector<int> ans;
        const int M = nums1.size(), N = nums2.size();
        int minI = max(0, k - N), maxI = min(k, M);
        for (int i = minI; i <= maxI; i++) {
            auto maxNum1 = maxNumber(nums1, i);
            auto maxNum2 = maxNumber(nums2, k - i);
            auto merged = merge(maxNum1, maxNum2);
            if (isLargerOrEqual(merged, 0, ans, 0)) ans = merged;
        }
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& nums, int k) {
        // 使组成的数最大：栈中是递减序列，对应取下一个更大的数；
        // 取k个数：当栈内数字个数+剩余可压栈个数>k时才可pop()，栈内数字个数<k个时才可push()
        const int N = nums.size();
        vector<int> stk;
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && nums[i] > stk.back()
                   && stk.size() + (N - i) > k) { // N-i是[i,N)的可压栈数字个数
                stk.pop_back();
            }
            if (stk.size() < k) stk.push_back(nums[i]);
        }
        return stk;
    }
    
    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ans;
        int size = nums1.size() + nums2.size();
        for (int i = 0, j = 0, k = 0; k < size; k++) {
            if (isLargerOrEqual(nums1, i, nums2, j)) ans.push_back(nums1[i++]);
            else ans.push_back(nums2[j++]);
        }
        return ans;
    }
       
    // 比较nums1[i1..]和nums2[i2..]的大小
    bool isLargerOrEqual(vector<int> &nums1, int i1, vector<int> &nums2, int i2) {
        while (i1 < nums1.size() && i2 < nums2.size() && nums1[i1] == nums2[i2]) {
            i1++;
            i2++;
        }
        return (i2 == nums2.size() || (i1 < nums1.size() && nums1[i1] > nums2[i2]));
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
