//
//  subarray-sums-divisible-by-k
//  https://leetcode.com/problems/subarray-sums-divisible-by-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> cnt; // sum=>count
        int runningSum = 0;
        cnt[runningSum] = 1;
        
        int ans = 0;
        for (int a : A) {
            runningSum = (runningSum + a % K + K) % K; // a可能为负
            // (runningSum-toFind)%K==0，(toFind==runningSum)%K
            ans += cnt[runningSum];
            cnt[runningSum]++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
