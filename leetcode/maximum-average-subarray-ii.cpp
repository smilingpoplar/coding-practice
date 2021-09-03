//
//  maximum-average-subarray-ii
//  https://leetcode.com/problems/maximum-average-subarray-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 最大均值一定在min(nums)和max(nums)之间
        double l = INT_MAX, u = INT_MIN;
        for (double num : nums) {
            l = min(l, num);
            u = max(u, num);
        }
        // 二分搜索猜
        while (u - l > 1e-5) {
            double mid = (l + u) / 2;
            if (enough(mid, nums, k)) u = mid;
            else l = mid;
        }
        return u;
    }
    
    bool enough(double m, vector<int> &nums, const int k) {
        // "所有"长>=k的子段均值 (a[i]+a[i+1]+...+a[j])/(j−i+1) <= m
        //  a[i]+a[i+1]+...+a[j] <= m*(j−i+1)，
        //  (a[i]−m)+(a[i+1]−m)+...+(a[j]−m)<=0 (1)，
        // (1)式左侧是关于m的递减函数，(1)式满足二分搜索的条件形式[0..0 1..1]
        // (1)式可用累加数组sum[i]=(a[0]-m)+(a[1]-m)...+(a[i]-m)计算
        // 对"所有"长>=k的子段，要 sum[j]-sum[i-1] <= 0，j-i+1>=k，
        // 即要sum[j]-sum[ <=j-k ] <= 0，sum[j]-min{ sum[ <=j-k ] } <= 0
        // 记currSum=sum[j]，minPrevSum=min{ sum[ <=j-k ] }，要currSum-minPrevSum<=0
        double currSum = 0;
        for (int j = 0; j < k; j++) {
            currSum += nums[j] - m;
        }
        if (currSum > 0) return false;

        double prevSum = 0, minPrevSum = 0;
        for (int j = k; j < nums.size(); j++) {
            currSum += nums[j] - m;
            prevSum += nums[j-k] - m;
            minPrevSum = min(minPrevSum, prevSum);
            if (currSum - minPrevSum > 0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
