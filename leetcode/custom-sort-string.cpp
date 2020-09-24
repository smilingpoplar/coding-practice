//
//  custom-sort-string
//  https://leetcode.com/problems/custom-sort-string/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> count;
        for (char c : T) 
            count[c]++;
        
        string ans;
        // S中出现的
        for (char c : S) {
            for (int i = 0; i < count[c]; i++)
                ans.push_back(c);
            count[c] = 0;
        }
        // S中没出现的
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < count[c]; i++)
                ans.push_back(c);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
