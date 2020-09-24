//
//  longest-string-chain
//  https://leetcode.com/problems/longest-string-chain/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), 
             [](const string &a, const string &b) { 
                 return a.size() < b.size(); });
        
        unordered_map<string, int> mp; // word=>chainLen
        int ans = 0;
        // 贪心法，每个单词看能不能接续上一单词
        for (auto &word : words) {
            int chainLen = 0;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i+1);
                chainLen = max(chainLen, mp[prev] + 1);
            }
            mp[word] = chainLen;
            ans = max(ans, chainLen);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
