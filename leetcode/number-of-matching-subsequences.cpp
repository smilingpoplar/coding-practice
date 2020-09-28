//
//  number-of-matching-subsequences
//  https://leetcode.com/problems/number-of-matching-subsequences/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        // 将word按待匹配char分桶，charToMatch=>{wordIdx,charIdxInWord}
        vector<pair<int, int>> buckets[128];
        for (int i = 0; i < words.size(); i++) {
            buckets[words[i][0]].push_back({i, 0});
        }
        
        for (char c : S) { // 待匹配字母c
            auto cBucket = buckets[c];
            buckets[c].clear();
            for (auto [wordIdx, charIdx] : cBucket) { // 桶中word都匹配掉c
                charIdx++;
                buckets[words[wordIdx][charIdx]].push_back({wordIdx, charIdx});
            }
        }
        // 全单词匹配的最后分到'\0'桶里
        return buckets[0].size();
    }
};

/*
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> pos(128); // char => pos_list
        for (int i = 0; i < S.size(); i++) 
            pos[S[i]].push_back(i);

        int ans = 0;
        for (auto &word : words) {
            if (isSubseq(word, pos)) ans++;
        }
        return ans;
    }
    
    bool isSubseq(const string &word, vector<vector<int>> &pos) {
        int lastIdx = -1;
        for (char c : word) {
            auto it = upper_bound(pos[c].begin(), pos[c].end(), lastIdx);
            if (it == pos[c].end()) return false;
            lastIdx = *it;
        }
        return true;
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
