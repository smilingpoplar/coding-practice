//
//  sentence-similarity-ii
//  https://leetcode.com/problems/sentence-similarity-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        // 直接用word作并查集的键
        unordered_map<string, string> parent;
        for (auto &p : pairs) {
            auto pw1 = find(p.first, parent), pw2 = find(p.second, parent);
            if (pw1 != pw2) parent[pw1] = pw2; // unite
        }
        
        for (int i = 0; i < words1.size(); i++) {
            auto &w1 = words1[i], &w2 = words2[i];
            if (w1 != w2 && find(w1, parent) != find(w2, parent)) return false;
        }
        return true;
    }
    
    string find(const string &s, unordered_map<string, string> &parent) {
        if (!parent.count(s)) parent[s] = s;
        
        if (parent[s] != s) 
            parent[s] = find(parent[s], parent);
        return parent[s];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
