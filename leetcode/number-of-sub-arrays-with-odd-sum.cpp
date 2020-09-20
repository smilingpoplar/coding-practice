//
//  number-of-sub-arrays-with-odd-sum
//  https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // 设odd[i]表示以arr[i]结尾的、arr[0..i]的"和为奇数"的、子段个数，
        //   even[i]                            和为偶数
        // 若arr[i]是奇数，
        //  odd[i]=even[i-1]+1 /*+1因为arr[i]单独作为一个子段*/
        //  even[i]=odd[i-1]，
        // 若arr[i]是偶数，
        //  odd[i]=odd[i-1]
        //  even[i]=even[i-1]+1 /*+1因为arr[i]单独作为一个子段*/，
        // 所求为sum(odd[i])
        // 第i项只依赖于第i-1项，省掉i这维，i仍从左往右遍历
        // arr[i]是奇数时，even=odd，odd=even+1
        //         偶数时，even++
        const int MOD = 1e9 + 7;
        int ans = 0;
        vector<int> dp(2); // even,odd
        for (int num : arr) {
            if (num & 1) {
                dp = { dp[1], dp[0] + 1};
            } else {
                dp[0]++;
            }
            ans = (ans + dp[1]) % MOD;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
