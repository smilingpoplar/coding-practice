//
//  sentence-screen-fitting
//  https://leetcode.com/problems/sentence-screen-fitting/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        // 把word+" "+word+" "+...无限扩展
        string s;
        for (auto &word : sentence)
            s += word + " ";
        int len = s.size();
        
        int cnt = 0; // 总共输入了多少字符
        for (int i = 0; i < rows; i++) {
            cnt += cols; // 尝试键入一满行
            while (cnt > 0 && s[cnt % len] != ' ') // 若对着单词中间则回退
                cnt--;
            cnt++;   // 跳过空格
        }
        return cnt / len;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
