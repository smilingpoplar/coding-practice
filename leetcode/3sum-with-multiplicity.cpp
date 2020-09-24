//
//  3sum-with-multiplicity
//  https://leetcode.com/problems/3sum-with-multiplicity/
//
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
        // 取三个数a<=b<=c，使和为target
        for (auto &e1 : cnt) {
            for (auto &e2 : cnt) {
                int a = e1.first, b = e2.first, c = target - a - b;
                if (a > b || !cnt.count(c) || b > c) continue;
                if (a == b) {
                    if (b == c) ans += cnt[a] * (cnt[a] - 1) * (cnt[a] - 2) / 6; // cnt[a]选3
                    else ans += cnt[a] * (cnt[a] - 1) / 2 * cnt[c]; // cnt[a]选2
                } else {
                    if (b == c) ans += cnt[a] * cnt[b] * (cnt[b] - 1) / 2; // cnt[b]选2
                    else ans += cnt[a] * cnt[b] * cnt[c];
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
