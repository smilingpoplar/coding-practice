//
//  palindrome-permutation
//  https://leetcode.com/problems/palindrome-permutation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> mp;
        int count = 0;
        for (char c : s) {
            mp[c]++;
            if (mp[c] % 2 == 1) count++;
            else count--;
        }
        return count <= 1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
