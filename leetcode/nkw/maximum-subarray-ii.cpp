//
//  maximum-subarray-ii
//  NC166 连续子数组的最大和(二)
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // 设dp[i]表示以a[i]结尾的a[0..i]的子段最大和
        // dp[i] =  max{ dp[i-1] + a[i], a[i] }
        // 用l[i]记录对应dp[i]的左右下标
        const int N = array.size();
        vector<int> dp(N, 0);
        vector<int> l(N);
        int maxsum = INT_MIN, ansL, ansR;
        for (int i = 0; i < N; i++) {
            // dp[i] = max(dp[i-1], 0) + array[i];
            if (i > 0 && dp[i - 1] >= 0) {
                dp[i] = dp[i - 1] + array[i];
                l[i] = l[i - 1];
            } else {
                dp[i] = array[i];
                l[i] = i;
            }

            if (dp[i] >= maxsum) {
                maxsum = dp[i];
                ansL = l[i];
                ansR = i;
            }
        }

        vector<int> ans;
        for (int i = ansL; i <= ansR; i++) {
            ans.push_back(array[i]);
        }
        return ans;
    }
};
