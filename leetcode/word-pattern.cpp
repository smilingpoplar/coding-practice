//
//  word-pattern
//  https://leetcode.com/problems/word-pattern/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // 把一一对应的pattern中字母和str中单词同时映射到[1..N]
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        string w;
        istringstream iss(str);
        int i = 0, N = pattern.size();
        while (iss >> w) {
            if (i == N) return false; // str中单词更多
            char p = pattern[i];
            if (p2i[p] != w2i[w]) return false;
            p2i[p] = w2i[w] = ++i;
        }
        return i == N;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
