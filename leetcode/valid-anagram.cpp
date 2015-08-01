//
//  valid-anagram
//  https://leetcode.com/problems/valid-anagram/
//
//  Created by smilingpoplar on 15/8/1.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 排序
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
*/

#include <vector>

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 计数
        if (s.size() != t.size()) return false;
        auto count = vector<int>(26, 0); // 只有小写字母
        for (int i = 0; i < s.size(); ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }
        for (int c : count) {
            if (c != 0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isAnagram("rat", "car");

    return 0;
}
