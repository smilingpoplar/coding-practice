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
            s += word + " "; // 句末有换行符
        int len = s.size();
        
        int left = 0; // 屏幕左侧正对着哪个字符
        for (int i = 0; i < rows; i++) {
            left += cols; // 尝试键入一满行
            while (left > 0 && s[left % len] != ' ') // 若对着单词中间则回退
                left--;
            left++;   // 跳过空格或换行符
        }
        return left / len;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
