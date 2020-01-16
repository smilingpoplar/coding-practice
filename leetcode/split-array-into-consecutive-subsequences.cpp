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
        unordered_map<int, int> count;
        for (int x : nums) count[x]++;

        // 数x优先扩展旧序列，即使旧序列太长也可拆分成多个新序列
        unordered_map<int, int> need;  // 扩展旧序列需要need[x]个x
        for (int x : nums) {
            if (count[x] == 0) continue;
            
            if (need[x] > 0) { // 优先扩展旧序列
                count[x]--;
                need[x]--;
                need[x+1]++;
            } else if (count[x+1] > 0 && count[x+2] > 0) { // x可作长>=3新序列的头
                count[x]--;
                count[x+1]--;
                count[x+2]--;
                need[x+3]++;
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
