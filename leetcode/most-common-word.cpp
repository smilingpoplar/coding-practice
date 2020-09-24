//
//  most-common-word
//  https://leetcode.com/problems/most-common-word/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (char &c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        unordered_set<string> st(banned.begin(), banned.end());

        unordered_map<string, int> cnt; // word=>count
        istringstream iss(paragraph);
        string word, ans;
        int maxCnt = INT_MIN;
        while (iss >> word) {
            if (st.count(word)) continue;
            if (++cnt[word] > maxCnt) {
                maxCnt = cnt[word];
                ans = word;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
