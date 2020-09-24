//
//  text-justification
//  https://leetcode.com/problems/text-justification/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        const auto wordCount = words.size();
        int lineStart = 0;
        int lineEnd = 0;
        while (lineStart < wordCount) {
            int lineCharCount = 0;
            for (lineEnd = lineStart; lineEnd < wordCount; lineEnd++) {
                auto wordSize = words[lineEnd].size();
                if (lineEnd > lineStart) ++wordSize;
                if (lineCharCount + wordSize > maxWidth) break;
                lineCharCount += wordSize;
            }
            // 一行：[lineStart, lineEnd)，字符数：lineCharCount
            ostringstream line;
            int extraSpace = maxWidth - lineCharCount;
            int lineWordCount = lineEnd - lineStart;
            if (lineEnd < wordCount) { // 非最后一行
                if (lineWordCount > 1) { // 一行多个单词
                    int averageExtraSpace = extraSpace / (lineWordCount - 1); // 每个间隔多分几个空格
                    int plusOneExtraSpace = extraSpace % (lineWordCount - 1); // 前几个间隔再多分一个空格
                    line << words[lineStart];
                    for (auto i = 1; i < lineWordCount; i++) {
                        if (i <= plusOneExtraSpace) {
                            line << " ";
                        }
                        for (auto j = 0; j <= averageExtraSpace; j++) {
                            line << " ";
                        }
                        line << words[lineStart + i];
                    }
                } else { // 一行一个单词
                    line << words[lineStart];
                    for (auto i = 0; i < extraSpace; i++) {
                        line << " ";
                    }
                }
            } else { // 最后一行
                line << words[lineStart];
                for (auto i = 1; i < lineWordCount; i++) {
                    line << " ";
                    line << words[lineStart + i];
                }
                for (auto i = 0; i < extraSpace; i++) {
                    line << " ";
                }
            }
            result.push_back(line.str());
            lineStart = lineEnd;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    Solution solution;
    auto result = solution.fullJustify(words, 16);
    for (const string &line : result) {
        cout << line << endl;
    }
    
    return 0;
}
