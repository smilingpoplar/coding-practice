//
//  maximum-number-of-coins-you-can-get
//  https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // 按3个分组，总选第2大d的
        // 先把最小的1/3去掉，在剩余数中隔两取一
        sort(piles.begin(), piles.end());
        const int N = piles.size();
        int ans = 0;
        for (int i = N / 3; i < N; i += 2) {
            ans += piles[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
