//
//  keyboard-row
//  https://leetcode.com/problems/keyboard-row/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
        unordered_map<char, int> mp;
        for (int i = 0; i < rows.size(); i++) {
            for (char c : rows[i]) {
                mp[c] = i;
            }
        }
        
        vector<string> ans;
        for (auto &word : words) {
            int row = -1;
            for (char c : word) {
                int cRow = mp[tolower(c)];
                if (row == -1) {
                    row = cRow;
                } else if (cRow != row) {
                    row = -1;
                    break;
                };
            }
            if (row != -1) ans.push_back(word);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {  
    return 0;
}
