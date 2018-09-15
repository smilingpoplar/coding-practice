//
//  random-pick-with-blacklist
//  https://leetcode.com/problems/random-pick-with-blacklist/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    unordered_map<int, int> mp; // 下标重映射
    int M;
public:
    Solution(int N, vector<int> blacklist) {
        unordered_set<int> st;
        for (int b : blacklist) {
            st.insert(b);
        }
        M = N - st.size();
        // N个数中只能选M个，将idx<M的不可选的数 =映射到=> idx>=M的可选的数
        for (int b : blacklist) {
            if (b < M) { 
                while (st.count(N - 1)) N--;
                mp[b] = N - 1;
                N--;
            } 
        }
        
        srand(time(NULL));
    }
    
    int pick() {
        int idx = rand() % M;
        return mp.count(idx) ? mp[idx] : idx;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
