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

        vector<vector<int>> stickerCharCnts;
        for (auto &sticker : stickers) {
            stickerCharCnts.push_back(countChar(sticker));
        }
        sort(target.begin(), target.end());
        return dfs(stickerCharCnts, target, memo);
    }
    
    // sticker,target变成charCnt[]参与运算
    int dfs(const vector<vector<int>> &stickers, const string &targetStr,
            unordered_map<string, int> &memo) {
        if (memo.count(targetStr)) return memo[targetStr];

        auto target = countChar(targetStr);
        int ans = INT_MAX;
        for (auto &sticker : stickers) {
            if (sticker[targetStr[0] - 'a'] == 0) continue; // 优化，至少要消掉首字母
            auto reduced = reduceTarget(target, sticker);
            int subAns = dfs(stickers, reduced, memo);
            if (subAns != -1) ans = min(ans, 1 + subAns);
        }
        memo[targetStr] = ans != INT_MAX ? ans : -1;
        return memo[targetStr];
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
            for (int k = 0; k < cnt; k++) {
                oss << char(i + 'a');
            }
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
