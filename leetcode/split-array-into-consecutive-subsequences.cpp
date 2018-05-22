//
//  split-array-into-consecutive-subsequences
//  https://leetcode.com/problems/split-array-into-consecutive-subsequences/
//
//  Created by smilingpoplar on 18/01/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count; // x有几个
        for (int x : nums) {
            ++count[x];
        }

        unordered_map<int, int> need;  // x作为序列尾的需求        
        for (int x : nums) {
            if (count[x] == 0) continue;
            
            if (need[x] > 0) { // x优先作为旧序列尾
                --count[x];
                --need[x];
                ++need[x+1];
            } else if (count[x+1] > 0 && count[x+2] > 0) { // x作为新序列头
                --count[x];
                --count[x+1];
                --count[x+2];
                ++need[x+3];
            } else {
                return false;
            }
        }
        
        return true;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
