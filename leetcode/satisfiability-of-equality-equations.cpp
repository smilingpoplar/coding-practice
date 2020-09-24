//
//  satisfiability-of-equality-equations
//  https://leetcode.com/problems/satisfiability-of-equality-equations/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // 相等的放到一个并查集，然后检查不等的应在不同并查集
        unordered_map<char, char> uf;
        for (auto &equa : equations) {
            if (equa[1] == '=') 
                unite(equa[0], equa[3], uf);
        }
        for (auto &equa : equations) {
            if (equa[1] == '!') {
                if (find(equa[0], uf) == find(equa[3], uf)) 
                    return false;
            }
        }
        return true;
    }
    
    char find(char a, unordered_map<char, char> &uf) {
        if (!uf.count(a)) uf[a] = a;

        if (uf[a] != a) {
            uf[a] = find(uf[a], uf);
        }
        return uf[a];
    }
    
    void unite(char a, char b, unordered_map<char, char> &uf) {
        char pa = find(a, uf), pb = find(b, uf);
        if (pa != pb) uf[pb] = pa;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
