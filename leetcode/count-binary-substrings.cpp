//
//  count-binary-substrings
//  https://leetcode.com/problems/count-binary-substrings/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.size() < 1) return 0;
        // 子串出现在0s1s交替的边界
        vector<int> groups;
        groups.push_back(1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i-1]) groups.push_back(1);
            else ++groups[groups.size() - 1];
        }
        
        int ans = 0;
        for (int i = 1; i < groups.size(); i++) {
            ans += min(groups[i], groups[i-1]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
