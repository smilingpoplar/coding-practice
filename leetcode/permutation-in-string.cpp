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
        const int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false;
        
        unordered_map<char, int> cnt;
        for (char c : s1) cnt[c]++;
        int distinct = cnt.size();
        
        for (int lo = 0, hi = 0; hi < len2; hi++) {
            if (--cnt[s2[hi]] == 0) distinct--;
            while (distinct == 0) {
                if (hi - lo + 1 == len1) return true;
                if (cnt[s2[lo]]++ == 0) distinct++;
                lo++;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
