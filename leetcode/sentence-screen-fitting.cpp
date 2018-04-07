//
//  sentence-screen-fitting
//  https://leetcode.com/problems/sentence-screen-fitting/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (auto &word : sentence)
            s += word + " "; // 句末要有空格才能接下一句
        int len = s.size();
        
        int start = 0; // 行首的单词在sss...中的索引
        for (int i = 0; i < rows; i++) {
            start += cols; // 尝试键入一满行
            // 如果上行末的单词被截断（即start位置非空格），start回退到被截断单词开头
            //              没被截断                   略过行首的空格
            while (start > 0 && s[start % len] != ' ')
                start--;
            start++;
        }
        return start / len;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
