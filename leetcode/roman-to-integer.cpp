//
//  roman-to-integer
//  https://leetcode.com/problems/roman-to-integer/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        // 从左到右累加当前值，如果当前字符比上一个大，补减上一个值
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += mp[s[i]];
            if (i > 0 && mp[s[i]] > mp[s[i-1]]) {
                ans -= 2 * mp[s[i-1]];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.romanToInt("XCVIII");
    
    return 0;
}
