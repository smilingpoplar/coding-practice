//
//  array-of-doubled-pairs
//  https://leetcode.com/problems/array-of-doubled-pairs/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> count;
        for (int a : A) 
            count[a]++;
        
        // 按绝对值从小到大处理
        vector<int> vals;
        for (auto &e : count)
            vals.push_back(e.first);
        sort(vals.begin(), vals.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        
        // 有值v就要有同等数量的值2v
        for (int v : vals) {
            if (count[v] > count[2*v]) return false;
            count[2*v] -= count[v];
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
