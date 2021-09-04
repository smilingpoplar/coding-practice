//
//  frog-jump
//  https://leetcode.com/problems/frog-jump/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        // 题目：河宽被分成一格格，已知某些格有石头。青蛙往前跳，初始跳1步，
        // 若上次跳k步、这次跳k-1、k、k+1步。问青蛙能否过河？
        // 写法类似bfs，石头当作顶点，jump[i]当作顶点i的出边
        unordered_map<int, set<int>> jump; // 某石头=>set{可以跳几步}
        jump[0].insert(1);

        set<int> st; // 快速判断某位置是否有石头
        for (int pos : stones) 
            st.insert(pos);
        
        for (int pos : stones) { // 遍历有石头的位置
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
