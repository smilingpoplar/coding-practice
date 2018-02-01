//
//  maximum-length-of-pair-chain
//  https://leetcode.com/problems/maximum-length-of-pair-chain/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // 找最多的不重叠区间数，先根据区间终点排序
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        
        int ans = 0;
        int end = INT_MIN;
        for (auto &p : pairs) {
            if (p[0] > end) {
                ans++;
                end = p[1];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
