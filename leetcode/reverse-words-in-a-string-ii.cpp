//
//  reverse-words-in-a-string-ii
//  https://leetcode.com/problems/reverse-words-in-a-string-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& str) {
        const int N = str.size();
        
        int start = 0;
        for (int i = 0; i < N; i++) {
            if (str[i] == ' ') {
                reverse(str, start, i - 1);
                start = i + 1;
            }
        }
        reverse(str, start, N - 1);

        reverse(str, 0, N - 1); // the whole
    }
    
    void reverse(vector<char> &str, int l, int r) {
        while (l < r) {
            swap(str[l++], str[r--]);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
