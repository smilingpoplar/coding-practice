//
//  split-concatenated-strings
//  https://leetcode.com/problems/split-concatenated-strings/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 题目：各单词按序排列成串、单词反转或不反转，从某单词的某字母后切一刀、其后的串+其前的串=>一个新串，找出这些新串中的最大串。
    string splitLoopedString(vector<string>& strs) {
        // 除了被切的单词，其他单词都应取原词和反转词中较大的那个。
        // 假设第i个单词被切，应在第i个单词的原词和反转词中每一个字母后都切一下，找出最大值
        
        // 每个单词取原词和反转词中较大的那个
        for (auto &str : strs) {
            string rev(str.rbegin(), str.rend());
            if (rev > str) str = rev;
        }
        
        string ans;
        const int N = strs.size();
        for (int i = 0; i < N; i++) {
            // 除第i个单词外的其他词
            string others;
            for (int j = i + 1; j < N; j++)
                others += strs[j];
            for (int j = 0; j < i; j++)
                others += strs[j];
            // 尝试切第i个单词
            string rev(strs[i].rbegin(), strs[i].rend());
            for (auto &s : {strs[i], rev}) {
                for (int k = 0; k < s.size(); k++) {
                    auto cutted = s.substr(k) + others + s.substr(0, k);
                    if (cutted > ans) ans = cutted;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
