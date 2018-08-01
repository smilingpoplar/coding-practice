//
//  freedom-trail
//  https://leetcode.com/problems/freedom-trail/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> mp; // ring_char => pos_list
        for (int i = 0; i < ring.size(); i++) {
            mp[ring[i]].push_back(i);
        }
        vector<vector<int>> memo(ring.size(), vector<int>(key.size(), -1));
        return search(ring, 0, key, 0, mp, memo);
    }
    
    // 原先ring[rIdx]正对12点，现在要变成key[kIdx]这个字符正对12点
    int search(const string &ring, int rIdx, const string &key, int kIdx, 
               unordered_map<char, vector<int>> &mp, vector<vector<int>> &memo) {
        if (kIdx == key.size()) return 0;
        if (memo[rIdx][kIdx] != -1) return memo[rIdx][kIdx];
        
        int ans = INT_MAX;
        for (int rNext : mp[key[kIdx]]) {
            int steps = abs(rIdx - rNext);
            steps = min(steps, (int)ring.size() - steps);
            steps++; // press button;
            steps += search(ring, rNext, key, kIdx + 1, mp, memo);
            ans = min(ans, steps);
        }
        memo[rIdx][kIdx] = ans;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
