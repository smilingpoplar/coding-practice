//
//  3sum-with-multiplicity
//  https://leetcode.com/problems/3sum-with-multiplicity/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long> cnt;
        for (int a : A) 
            cnt[a]++;
        
        const int MOD = 1e9 + 7;
        long ans = 0;
        for (auto &e1 : cnt) {
            for (auto &e2 : cnt) {
                int i = e1.first, j = e2.first, k = target - i - j;
                if (i > j || !cnt.count(k) || j > k) continue;
                // 至此 i <= j <= k
                if (i == j) {
                    if (j == k) ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                    else ans += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
                } else {
                    if (j == k) ans += cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
                    else ans += cnt[i] * cnt[j] * cnt[k];
                }
            }
            ans %= MOD;
        }        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
