//
//  reverse-words-in-a-string
//  https://leetcode.com/problems/reverse-words-in-a-string/
//
//  Created by smilingpoplar on 15/5/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        trimSpace(s);
        // 先单词求逆，再整串求逆
        const int N = (int)s.size();
        int i = 0;
        while (i < N) {
            int j = i;
            while (j < N && s[j] != ' ') ++j;
            reverse(s, i, j);
            i = j + 1;
        }
        reverse(s, 0, N);
    }
private:
    // 去头尾空格，合并中间空格，O(1)空间
    void trimSpace(string &s) {
        const size_t N = s.size();
        int i = 0;
        int j = 0;
        while (j < N && s[j] == ' ') ++j;
        while (j < N) {
            while (j < N && s[j] != ' ') {
                s[i] = s[j];
                ++i;
                ++j;
            }
            while (j < N && s[j] == ' ') {
                s[i] = s[j];
                ++j;
            }
            if (j < N) ++i;
        }
        s.resize(i);
    }
    
    // 反转s[start,end)
    void reverse(string &s, int start, int end) {
        for (int i = start, j = end - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

int main(int argc, const char * argv[]) {
    string s = "the sky is blue";
    Solution solution;
    solution.reverseWords(s);
    cout << s;
    
    return 0;
}
