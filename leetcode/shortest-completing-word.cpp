//
//  shortest-completing-word
//  https://leetcode.com/problems/shortest-completing-word/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> count(26, 0);
        for (char c : licensePlate)
            if (isalpha(c)) 
                count[tolower(c) - 'a']++;
        
        int shortest = INT_MAX;
        string ans;
        for (auto &word : words) {
            if (word.size() < shortest && isMatched(word, count)) {
                shortest = word.size();
                ans = word;
            }
        }
        return ans;        
    }
    
    bool isMatched(const string &word, vector<int> count) { // count是传值参数
        for (char c : word)
            count[c - 'a']--;
        
        for (int i = 0; i < count.size(); i++)
            if (count[i] > 0) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
