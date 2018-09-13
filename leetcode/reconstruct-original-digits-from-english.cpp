//
//  reconstruct-original-digits-from-english
//  https://leetcode.com/problems/reconstruct-original-digits-from-english/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        // 偶数的英文中刚好都有唯一字母：
        // 0 zero  唯一z
        // 1 one   删后唯一o
        // 2 two   唯一w
        // 3 three 删后唯一r
        // 4 four  唯一u
        // 5 five  删后唯一f
        // 6 six   唯一x
        // 7 seven 删后唯一v
        // 8 eight 唯一g
        // 9 nine  删后唯一i
        unordered_map<char, int> mp; // char=>count
        for (char c : s) mp[c]++;
        const vector<int> digits = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 }; // 按这顺序查找各数字
        const string ids = "zowrufxvgi"; // 各数字的标识字母
        const vector<string> words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        
        vector<int> count(10); // digit=>count
        for (int d : digits) {
            count[d] = mp[ids[d]];
            for (char c : words[d]) mp[c] -= count[d];
        }
        
        ostringstream oss;
        for (int i = 0; i < count.size(); i++)
            for (int j = 0; j < count[i]; j++)
                oss << i;
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
