//
//  number-of-matching-subsequences
//  https://leetcode.com/problems/number-of-matching-subsequences/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        // S很长，为效率只遍历一遍
        // 将words[]中单词按待匹配的首字母分桶
        vector<pair<int, int>> buckets[128]; // 待匹配字母 => vector[(单词idx, 待匹配字母idx)]
        for (int i = 0; i < words.size(); i++) {
            buckets[words[i][0]].push_back({i, 0});
        }
        
        for (char c : S) {
            auto list = buckets[c];
            buckets[c].clear();
            for (auto &p : list) { // list中单词都匹配一个字母
                buckets[words[p.first][++p.second]].push_back(p);
            }
        }
        // 全单词匹配的最后分到'\0'桶里
        return buckets[0].size();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
