//
//  number-of-equivalent-domino-pairs
//  https://leetcode.com/problems/number-of-equivalent-domino-pairs/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> cnt; // code=>count
        int ans = 0;
        for (auto &d : dominoes) {
            int code = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            // 新增code和同值code都能成对
            ans += cnt[code]++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
