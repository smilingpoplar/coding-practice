//
//  permutation-in-string
//  https://leetcode.com/problems/permutation-in-string/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int s1len = s1.size();
        const int s2len = s2.size();
        if (s1len > s2len) return false;
        
        vector<int> count(26, 0);
        for (int i = 0; i < s1len; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (allZeros(count)) return true;
        
        for (int i = s1len; i < s2len; i++) {
            count[s2[i] - 'a']--;
            count[s2[i - s1len] - 'a']++;
            if (allZeros(count)) return true;
        }
        return false;
    }
    
    bool allZeros(const vector<int> &count) {
        for (int c : count) {
            if (c != 0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
