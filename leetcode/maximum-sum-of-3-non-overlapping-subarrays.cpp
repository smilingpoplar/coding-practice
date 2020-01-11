//
//  maximum-sum-of-3-non-overlapping-subarrays
//  https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
//
//  Created by smilingpoplar on 18/01/19.
//  CopyrightIdx (c) 2015年 YangLe. All rightIdxs reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if (k * 3 > nums.size()) return { -1, -1, -1 };
        // 先算出所有k长的子段和，构成数组W
        vector<int> W(nums.size() - k + 1);
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        int iw = 0;
        W[iw++] = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i-k];
            W[iw++] = sum;
        }
        
        // 问题变成从W中取3个数ia、ib、ic，使W[ia]+W[ib]+W[ic]最大，不重叠要求ia+k<=ib、ib+k<=ic。
        // 三个数一般想法是固定住中间的数，故先选定中间数ib。那么ia只要在[0..ib-k]中找最大值的最左出现，
        // ic只要在[ib+k..N-1]中找最大值的最左出现。选最左出现为满足字典序最小。
        const int N = W.size();
        vector<int> leftIdx(N);
        int maxIdx = 0;
        for (int i = 0; i < N; i++) {
            if (W[i] > W[maxIdx]) maxIdx = i; // 最大值的最左出现
            leftIdx[i] = maxIdx;
        }

        vector<int> rightIdx(N);
        maxIdx = N - 1;
        for (int j = N - 1; j >= 0; j--) {
            if (W[j] >= W[maxIdx]) maxIdx = j; // 最大值的最左出现，注意这里>=号
            rightIdx[j] = maxIdx;
        }
        
        // 选三个数{ia,ib,ic}, ia+k<=ib, ib+k<=ic
        int maxSum = INT_MIN;
        vector<int> ans = { -1, -1, -1 };
        for (int ib = k; ib < N - k; ib++) {
            int ia = leftIdx[ib-k], ic = rightIdx[ib+k];
            int sum = W[ia] + W[ib] + W[ic];
            if (sum > maxSum) {
                maxSum = sum;
                ans = { ia, ib, ic };
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
