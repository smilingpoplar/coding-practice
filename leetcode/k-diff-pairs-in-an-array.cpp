//
//  k-diff-pairs-in-an-array
//  https://leetcode.com/problems/k-diff-pairs-in-an-array/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        map<int, int> count;
        for (int num : nums)
            count[num]++;
        
        int ans = 0;
        for (auto &e : count) {
            if (k == 0) ans += (e.second > 1);
            else ans += (count.find(e.first + k) != count.end());
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
