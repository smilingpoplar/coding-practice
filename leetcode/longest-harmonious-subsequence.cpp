//
//  longest-harmonious-subsequence
//  https://leetcode.com/problems/longest-harmonious-subsequence/
//
//  Created by smilingpoplar on 17/12/02.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        
        int ans = 0;
        for (auto &e : mp) {
            int x = e.first;
            if (!mp.count(x+1)) continue;
            ans = max(ans, mp[x] + mp[x+1]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
