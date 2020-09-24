//
//  detect-capital
//  https://leetcode.com/problems/detect-capital/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty()) return true;
        if (all_of(word.begin() + 1, word.end(), [](char c) { return islower(c); })) return true;
        if (all_of(word.begin(), word.end(), [](char c) { return isupper(c);})) return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
