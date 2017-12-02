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
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        
        int maxL = 0;
        for (const auto &kv : m) {
            if (m.find(kv.first + 1) != m.end()) {
                maxL = max(maxL, kv.second + m[kv.first + 1]);
            }
        }
        return maxL;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
