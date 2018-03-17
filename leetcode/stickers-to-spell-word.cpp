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
        // 设dp[str]表示已排序串str需要的最少贴纸数，已知dp[""]=0
        unordered_map<string, int> dp;
        dp[""] = 0;
        sort(target.begin(), target.end());
        vector<vector<int>> stickerCharsArray;
        for (auto &sticker : stickers) {
            stickerCharsArray.push_back(countChars(sticker));
        }
        return minStickers(target, dp, stickerCharsArray);
    }
    
    int minStickers(string target, unordered_map<string, int> &dp, 
                    const vector<vector<int>> &stickerCharsArray) {
        if (dp.count(target)) return dp[target];
        int ans = INT_MAX;
        auto targetChars = countChars(target);
        for (auto &stickerChars : stickerCharsArray) {
            if (stickerChars[target[0] - 'a'] <= 0) continue;
            string reduced = reduceTarget(targetChars, stickerChars);
            int subAns = minStickers(reduced, dp, stickerCharsArray);
            if (subAns != -1) ans = min(ans, 1 + subAns);
        }
        if (ans == INT_MAX) ans = -1;
        dp[target] = ans;    
        return ans;
    }
    
    vector<int> countChars(const string &s) {
        vector<int> count(26, 0);
        for (char c : s) {
            ++count[c - 'a'];
        }
        return count;
    }
    
    string reduceTarget(vector<int> target, const vector<int> &v) {
        ostringstream oss;
        for (int i = 0; i < target.size(); i++) {
            target[i] = max(0, target[i] - v[i]);
            for (int k = 0; k < target[i]; k++) {
                oss << char(i + 'a');
            }
        }
        return oss.str();        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
