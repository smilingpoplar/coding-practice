//
//  pyramid-transition-matrix
//  https://leetcode.com/problems/pyramid-transition-matrix/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, string> trans;
        for (auto s : allowed) {
            trans[s.substr(0, 2)].push_back(s[2]);
        }
        return canPyramid(bottom, trans);
    }
    
    // 能否由bottom起堆个金字塔
    bool canPyramid(string &bottom, unordered_map<string, string> &trans) {
        if (bottom.size() == 1) return true;
        for (int i = 0; i < bottom.size() - 1; i++) {
            if (trans.find(bottom.substr(i, 2)) == trans.end()) return false;
        }
        vector<string> nexts;
        string next;
        search(bottom, 0, trans, next, nexts); // 得到上一层的各种可能
        for (auto &next : nexts) {
            if (canPyramid(next, trans)) return true;
        }
        return false;
    }
    
    void search(string &bottom, int idx, unordered_map<string, string> &trans,
                string &next, vector<string> &nexts) {
        if (idx == bottom.size() - 1) {
            nexts.push_back(next);
            return;
        }
        for (char c : trans[bottom.substr(idx, 2)]) {
            next.push_back(c);
            search(bottom, idx + 1, trans, next, nexts);
            next.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
