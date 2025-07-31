//
//  k-diff-pairs-in-an-array
//  https://leetcode.com/problems/k-diff-pairs-in-an-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        
        int ans = 0;
        for (auto [num, count] : cnt) {
            if (k == 0) ans += count >= 2;
            else ans += cnt.count(num + k);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
