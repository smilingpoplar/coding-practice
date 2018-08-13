//
//  number-of-longest-increasing-subsequence
//  https://leetcode.com/problems/number-of-longest-increasing-subsequence/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int N = nums.size();
        vector<int> len(N, 1); // 以nums[i]结尾的递增子序列长度
        vector<int> cnt(N, 1); //      ...              个数
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (len[j] + 1 > len[i]) { // 新的最长
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (len[j] + 1 == len[i]) { // 已知最长
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        
        int longest = INT_MIN;
        for (int l : len) {
            longest = max(longest, l);
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (len[i] == longest) {
                ans += cnt[i];
            }
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
