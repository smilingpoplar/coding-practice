//
//  implement-magic-dictionary
//  https://leetcode.com/problems/implement-magic-dictionary/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MagicDictionary {
    unordered_set<string> words;
    unordered_map<string, int> count;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto &w : dict) {
            words.insert(w);
            auto expanded = expandWord(w);
            for (auto &e : expanded) {
                count[e]++;
            }
        }
    }
    
    vector<string> expandWord(string word) {
        vector<string> ans;
        for (char &c : word) {
            char origin = c;
            c = '*';
            ans.push_back(word);
            c = origin;
        }
        return ans;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        auto expanded = expandWord(word);
        for (auto &e : expanded) {
            if (count[e] > 1 || (count[e] == 1 && !words.count(word))) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
