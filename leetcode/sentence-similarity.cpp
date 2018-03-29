//
//  sentence-similarity
//  https://leetcode.com/problems/sentence-similarity/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;

        unordered_map<string, unordered_set<string>> mp; // word=>similars
        for (auto &pair : pairs) {
            mp[pair.first].insert(pair.second);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] 
                && !mp[words1[i]].count(words2[i]) 
                && !mp[words2[i]].count(words1[i])) 
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
