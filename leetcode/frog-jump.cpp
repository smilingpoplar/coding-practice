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
        set<int> st; // 记录哪些位置有石头
        for (int pos : stones)
            st.insert(pos);
        
        unordered_map<int, set<int>> jump; // 记录从某位置可以跳几步
        jump[0].insert(1);
        
        for (int pos : stones) {
            for (int k : jump[pos]) {
                int next = pos + k;
                if (!st.count(next)) continue;
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
