//
//  bold-words-in-string
//  https://leetcode.com/problems/bold-words-in-string/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 同616：https://leetcode.com/problems/add-bold-tag-in-string/
    string boldWords(vector<string>& words, string S) {
        // 用bold[]记录各字符是否加粗
        const int N = S.size();
        vector<bool> bold(N, false);
        for (int i = 0; i < N; i++) {
            for (auto &word : words) {
                if (startsWith(word, S, i)) {
                    for (int j = i; j < i + word.size(); j++) {
                        bold[j] = true;
                    }
                }  
            }
        }      
        // 根据bold[]来添加<b>标签
        ostringstream oss;
        for (int i = 0; i < N; i++) {
            if (bold[i] && (i == 0 || !bold[i-1])) // 第一个加粗的字符
                oss << "<b>";
            oss << S[i];
            if (bold[i] && (i == N-1 || !bold[i+1])) // 最后一个加粗的字符
                oss << "</b>";
        }
        return oss.str();    
    }
    
    bool startsWith(const string &prefix, const string &str, int pos) {
        if (pos + prefix.size() > str.size()) return false;
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != str[pos + i]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
