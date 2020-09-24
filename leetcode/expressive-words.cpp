//
//  expressive-words
//  https://leetcode.com/problems/expressive-words/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        for (auto &word : words) {
            ans += canExtend(word, S);
        }
        return ans;
    }
    
    bool canExtend(const string &word, const string &S) {
        int i = 0, j = 0;
        while (i < word.size() && j < S.size()) {
            if (word[i] != S[j]) return false;
            int startI = i, startJ = j;
            while (i < word.size() && word[i] == word[startI]) i++;
            while (j < S.size() && S[j] == S[startJ]) j++;
            int cntInWord = i - startI, cntInS = j - startJ;
            if (cntInS < cntInWord) return false;
            if (cntInS < 3 && cntInWord != cntInS) return false;
        }
        return (i == word.size() && j == S.size());
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
