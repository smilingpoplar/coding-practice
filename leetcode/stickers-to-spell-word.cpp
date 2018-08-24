//
//  stickers-to-spell-word
//  https://leetcode.com/problems/stickers-to-spell-word/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        // 设memo[str]表示已排序串str需要的最少贴纸数，已知memo[""]=0
        unordered_map<string, int> memo;
        memo[""] = 0;

        vector<vector<int>> stickersCC; // CC指CharCount
        for (auto &sticker : stickers) {
            stickersCC.push_back(countChar(sticker));
        }
        sort(target.begin(), target.end());
        return dfs(stickersCC, target, memo);
    }
    
    int dfs(const vector<vector<int>> &stickersCC, const string &target,
            unordered_map<string, int> &memo) {
        if (memo.count(target)) return memo[target];

        auto targetCC = countChar(target);
        int ans = INT_MAX;
        for (auto &stickerCC : stickersCC) {
            if (stickerCC[target[0] - 'a'] == 0) continue; // 优化，至少要消掉首字母
            auto reduced = reduceTarget(targetCC, stickerCC);
            int subAns = dfs(stickersCC, reduced, memo);
            if (subAns != -1) ans = min(ans, 1 + subAns);
        }
        memo[target] = ans != INT_MAX ? ans : -1;
        return memo[target];
    }
    
    vector<int> countChar(const string &s) {
        vector<int> ans(26, 0);
        for (char c : s) {
            ans[c - 'a']++;
        }
        return ans;
    }
    
    // a - b
    string reduceTarget(const vector<int> &a, const vector<int> &b) {
        ostringstream oss;
        for (int i = 0; i < a.size(); i++) {
            int cnt = max(0, a[i] - b[i]);
            oss << string(cnt, i + 'a');
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
