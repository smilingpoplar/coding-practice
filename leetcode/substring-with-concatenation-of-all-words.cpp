//
//  substring-with-concatenation-of-all-words.cpp
//  https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//
//  Created by smilingpoplar on 15/5/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // N个长为M的单词构成长为N*M的子串，子串里的单词一个个地看，
        // 若某个单词在字典中不存在，则子串中迄今判断过的单词起始位置都不能作为新子串起始
        // 若某个单词多余重复，则新子串可能从firstIndex[word]+wordSize开始
        vector<int> result;
        if (words.empty()) return result;
        const int wordSize = (int)words[0].size();
        const int substringSize = (int)(wordSize * words.size());
        unordered_map<string, int> wordCount;
        for (const auto &word : words) {
            ++wordCount[word];
        }
        
        unordered_map<string, int> count;
        for (int i = 0; i < wordSize; i++) {
            int substringStart = i;
            int wordStart = substringStart;
            count.clear();
            while (wordStart + wordSize <= s.size()) {
                string word = s.substr(wordStart, wordSize);
                if (wordCount.find(word) == wordCount.end()) { // 单词不存在
                    substringStart = wordStart + wordSize;
                    wordStart = substringStart;
                    count.clear();
                } else {
                    if (count[word] >= wordCount[word]) { // 多余重复单词
                        substringStart = firstIndex(s, substringStart, wordStart, word) + wordSize;
                        wordStart += wordSize;
                    } else {
                        ++count[word];
                        if (wordStart + wordSize == substringStart + substringSize) { // 满足条件
                            result.push_back(substringStart);
                            substringStart += wordSize;
                            wordStart = substringStart;
                            count.clear();
                        } else {
                            wordStart += wordSize;
                        }
                    }
                }
            }
        }
        
        return result;
    }
private:
    int firstIndex(const string &s, int start, int end, const string &word) {
        for (int i = start; i < end; i += word.size()) {
            if (word == s.substr(i, word.size())) return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<string> words = {"a","b","a"};
    auto result = solution.findSubstring("abababab", words);
    for (int index : result) {
        cout << index << " ";
    }
    
    return 0;
}
