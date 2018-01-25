//
//  frog-jump
//  https://leetcode.com/problems/frog-jump/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        set<int> S; // 记录各石头是否存在
        for (int stone : stones)
            S.insert(stone);
        
        unordered_map<int, set<int>> jump; // 记录各石头上可以跳几步
        jump[0].insert(1);
        
        for (int stone : stones) {
            if (jump.find(stone) == jump.end()) continue;
            
            for (int k : jump[stone]) {
                int next = stone + k;
                if (S.find(next) == S.end()) continue;
                if (next == stones.back()) return true;
                if (k - 1 > 0) jump[next].insert(k - 1);
                jump[next].insert(k);
                jump[next].insert(k + 1);
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
