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
        // 假设x是最大均值，“所有”长>=k的子数组(a[i]+a[i+1]+...+a[j])/(j−i+1) <= x，
        // a[i]+a[i+1]+...+a[j] <= x∗(j−i+1)，(a[i]−x)+(a[i+1]−x)+...+(a[j]−x)<=0
        // 转化成"存在"条件：如果x不是最大均值，"存在"长>=k的子数组，使(a[i]−x)+(a[i+1]−x)+...+(a[j]−x)>0
        // 用二分搜索来猜最大均值。如果mid满足上述"存在"条件，则mid不是最大均值，mid可猜大点；否则，mid可猜小点。
        // 当abs(u-l)<=10^-5时收敛停止。
        // 这个"存在"条件可用累加数组sum[]判断，只要判断sum[i] - min{sum[j]} > 0, j=[0..i-k]。
        double l = INT_MAX, u = INT_MIN;
        for (double num : nums) {
            l = min(l, num);
            u = max(u, num);
        }
        while (u - l > 0.00001) {
            double mid = (l + u) / 2;
            if (guess(mid, nums, k)) l = mid;
            else u = mid;
        }
        return u;
    }
    
    bool guess(double x, vector<int> &nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i] - x;
        }
        if (sum > 0) return true;

        double prevSum = 0, minPrevSum = 0;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - x;
            prevSum += nums[i-k] - x;
            minPrevSum = min(minPrevSum, prevSum);
            if (sum - minPrevSum > 0) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
