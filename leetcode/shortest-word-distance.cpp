//
//  shortest-word-distance
//  https://leetcode.com/problems/shortest-word-distance/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX;
        // i1,i2是最近见到word1,word2的位置
        int i1 = -1, i2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) i1 = i;
            else if (words[i] == word2) i2 = i;
            if (i1 != -1 && i2 != -1) ans = min(ans, abs(i1 - i2));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
