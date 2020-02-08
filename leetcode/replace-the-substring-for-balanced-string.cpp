//
//  replace-the-substring-for-balanced-string
//  https://leetcode.com/problems/replace-the-substring-for-balanced-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int balancedString(string s) {
        // balanced串中各字符要出现K次，此题变成：
        // 找各字符出现cntInS-K次的最小窗口长
        const int N = s.size(), K = N / 4;
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        int ans = INT_MAX;
        for (int lo = 0, hi = 0; hi < N; hi++) {
            count[s[hi]]--;
            while (lo < N 
                   && count['Q'] - K <= 0 && count['W'] - K <= 0 
                   && count['E'] - K <= 0 && count['R'] - K <= 0) {
                ans = min(ans, hi - lo + 1);
                count[s[lo]]++;
                lo++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
