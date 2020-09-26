//
//  longest-harmonious-subsequence
//  https://leetcode.com/problems/longest-harmonious-subsequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }

        int ans = 0;
        for (auto& [x, _] : cnt) {
            if (!cnt.count(x+1)) continue;
            ans = max(ans, cnt[x] + cnt[x+1]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
