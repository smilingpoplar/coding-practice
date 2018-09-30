//
//  uncommon-words-from-two-sentences
//  https://leetcode.com/problems/uncommon-words-from-two-sentences/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> cnt; // word=>count
        stringstream ass(A), bss(B);
        string word;
        while (ass >> word) cnt[word]++;
        while (bss >> word) cnt[word]++;
        
        vector<string> ans;
        for (auto &e : cnt) {
            if (e.second == 1) {
                ans.push_back(e.first);
            }
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
