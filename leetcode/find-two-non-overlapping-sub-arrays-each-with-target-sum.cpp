//
//  maximal-square
//  https://leetcode.com/problems/maximal-square/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    const int INF = 1e9; 
    int minSumOfLengths(vector<int>& arr, int target) {
        // 全为正数，可用滑动数组
        auto left = minLens(arr, target, false);
        auto right = minLens(arr, target, true);
        int ans = INF;
        for (int i = 1; i < arr.size(); i++) {
            ans = min(ans, left[i-1] + right[i]);
        }
        return ans == INF ? -1 : ans;
    }

    vector<int> minLens(vector<int> arr, int target, bool fromRight) {
        // ans[i]表示arr[0..i]的、和为target的、最小长度
        if (fromRight) reverse(arr.begin(), arr.end());
        const int N = arr.size();
        vector<int> ans(N);
        int sum = 0, leftMin = INF;
        for (int hi = 0, lo = 0; hi < N - 1; hi++) {
            sum += arr[hi];
            while (sum > target) {
                sum -= arr[lo++];
            }
            if (sum == target) {
                leftMin = min(leftMin, hi - lo + 1);
            }
            ans[hi] = leftMin;
        }
        if (fromRight) reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
