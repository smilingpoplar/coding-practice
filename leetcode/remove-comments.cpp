//
//  remove-comments
//  https://leetcode.com/problems/remove-comments/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool inBlock = false;
        string newLine;
        vector<string> ans;
        for (auto &line : source) {
            int len = line.size();
            for (int i = 0; i < len; i++) {
                if (!inBlock) {
                    if (line[i] == '/' && i + 1 < len && line[i+1] == '*') {
                        inBlock = true;
                        i++;
                    } else if (line[i] == '/' && i + 1 < len && line[i+1] == '/') {
                        break;
                    } else {
                        newLine.push_back(line[i]);
                    }       
                } else {
                    if (line[i] == '*' && i + 1 < len && line[i+1] == '/') {
                        inBlock = false;
                        i++;
                    }
                }
            }
            if (!inBlock && !newLine.empty()) {
                ans.push_back(newLine);
                newLine.clear();
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
