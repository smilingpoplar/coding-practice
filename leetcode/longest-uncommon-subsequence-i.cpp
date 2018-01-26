//
//  longest-uncommon-subsequence-i
//  https://leetcode.com/problems/longest-uncommon-subsequence-i/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        if (a.size() > b.size()) return a.size();
        return b.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
