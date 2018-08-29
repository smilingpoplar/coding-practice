//
//  shortest-word-distance-ii
//  https://leetcode.com/problems/shortest-word-distance-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class WordDistance {
    unordered_map<string, vector<int>> mp; // word => idxList
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto list1 = mp[word1];
        auto list2 = mp[word2];
        // 找两有序数组中差值最小的一对
        int ans = INT_MAX;
        int i = 0, j = 0;
        while (i < list1.size() && j < list2.size()) {
            ans = min(ans, abs(list1[i] - list2[j]));
            if (list1[i] < list2[j]) i++;
            else j++;
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
