//
//  first-unique-character-in-a-string
//  https://leetcode.com/problems/first-unique-character-in-a-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
