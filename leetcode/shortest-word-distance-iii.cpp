//
//  shortest-word-distance-iii
//  https://leetcode.com/problems/shortest-word-distance-iii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        const bool same = word1 == word2;
        int ans = INT_MAX;
        // i1,i2是最近见到word1,word2的位置。
        // 如果word1和word2相同，i1是上一次见到word的位置，i2是这一次见到word的位置。
        int i1 = -1, i2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) i1 = i;
            if (words[i] == word2) {
                if (same) i1 = i2; // i1是上一次见到word的位置
                i2 = i;
            }
            if (i1 != -1 && i2 != -1) ans = min(ans, abs(i1 - i2));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
