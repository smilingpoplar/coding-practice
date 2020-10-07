//
//  letter-tile-possibilities
//  https://leetcode.com/problems/letter-tile-possibilities/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26); // char=>count
        for (char c : tiles) {
            cnt[c - 'A']++;
        }
        return dfs(cnt);
    }
    
    int dfs(vector<int> &cnt) {
        int ans = 0;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0) continue;
            cnt[i]--;
            ans++;    // 单独使用tiles[i]作为序列
            ans += dfs(cnt); // tiles[i]加长tiles[i+1..]对应的序列
            cnt[i]++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
