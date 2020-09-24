//
//  remove-all-adjacent-duplicates-in-string-ii
//  https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for (char c : s) {
            if (stk.empty() || stk.back().first != c) {
                stk.push_back({c, 1});
            } else if (++stk.back().second == k) {
                stk.pop_back();
            }
        }
        string ans;
        for (auto &e : stk) {
            ans += string(e.second, e.first);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
