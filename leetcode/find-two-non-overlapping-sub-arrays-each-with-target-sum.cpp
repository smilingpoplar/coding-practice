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
    int minSumOfLengths(vector<int>& arr, int target) {
        // 全为正数，可用滑动数组
        // 先从左往右扫描，再从右往左扫描
        const int N = arr.size(), INF = 1e9;
        vector<int> left(N);
        for (int hi = 0, lo = 0, sum = 0, leftLen = INF; hi < N - 1; hi++) {
            sum += arr[hi];
            while (sum > target) {
                sum -= arr[lo++];
            }
            if (sum == target) {
                leftLen = min(leftLen, hi - lo + 1);
            }
            left[hi] = leftLen;
        }

        int ans = INF;
        for (int lo = N - 1, hi = N - 1, sum = 0, rightLen = INF; lo >= 1; lo--) {
            sum += arr[lo];
            while (sum > target) {
                sum -= arr[hi--];
            }
            if (sum == target) {
                rightLen = min(rightLen, hi - lo + 1);
                ans = min(ans, left[lo-1] + rightLen);
            }
        }
        return ans == INF ? -1 : ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
