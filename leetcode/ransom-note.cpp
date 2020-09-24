//
//  ransom-note
//  https://leetcode.com/problems/ransom-note/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
        for (char c : magazine) {
            count[c]++;
        }
        for (char c : ransomNote) {
            if (count[c] <= 0) return false;
            count[c]--;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
