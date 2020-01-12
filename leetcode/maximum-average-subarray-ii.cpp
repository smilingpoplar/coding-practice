//
//  maximum-average-subarray-ii
//  https://leetcode.com/problems/maximum-average-subarray-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 最大均值一定在数组最大值和最小值之间。假设m是最大均值，
        // “所有”长>=k子段均值 (a[i]+a[i+1]+...+a[j])/(j−i+1) <= m，a[i]+a[i+1]+...+a[j] <= m*(j−i+1)，
        // 即 所有长>=k子段 (a[i]−m)+(a[i+1]−m)+...+(a[j]−m)<=0 (1)
        // 猜m的值，若m猜得太小，(1)式不成立；若m猜得太大，(1)式肯定成立
        // 将(1)式作为二分搜索条件enough(m)，符合返回[0 0 ... 0 1 1 ...]的要求
        // (1)式可用累加数组sum[i]=(a[0]-m)+(a[1]-m)...+(a[i]-m)判断
        // 对"所有"长>=k的子段，只要sum[j]-min{sum[i|i<=j-k]}<=0
        double l = INT_MAX, u = INT_MIN;
        for (double num : nums) {
            l = min(l, num);
            u = max(u, num);
        }
        while (u - l > 1e-5) {
            double mid = (l + u) / 2;
            if (enough(mid, nums, k)) u = mid;
            else l = mid;
        }
        return u;
    }
    
    bool enough(double m, vector<int> &nums, const int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i] - m;
        }
        if (sum > 0) return false;

        double prevSum = 0, minPrevSum = 0;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - m;
            prevSum += nums[i-k] - m;
            minPrevSum = min(minPrevSum, prevSum);
            if (sum - minPrevSum > 0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
