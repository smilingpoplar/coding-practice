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
        // zero  唯一z 一
        // one   删后唯一o 六
        // two   唯一w 二
        // three 删后唯一r 七
        // four  唯一u 三
        // five  删后唯一f 八
        // six   唯一x 四
        // seven 删后唯一v 九
        // eight 唯一g 五
        // nine  删后唯一i 十
        unordered_map<char, int> mp; // char=>count
        for (char c : s) mp[c]++;
        vector<int> digits = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
        vector<string> words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        string ids = "zowrufxvgi";
        
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
