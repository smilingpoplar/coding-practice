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
        vector<string> ans;
        string line;
        for (auto &s : source) {
            int len = s.size();
            for (int i = 0; i < len; i++) {
                if (!inBlock) {
                    if (s[i] == '/' && i + 1 < len && s[i+1] == '*') {
                        inBlock = true;
                        i++;
                    } else if (s[i] == '/' && i + 1 < len && s[i+1] == '/') {
                        break;
                    } else {
                        line.push_back(s[i]);
                    }       
                } else {
                    if (s[i] == '*' && i + 1 < len && s[i+1] == '/') {
                        inBlock = false;
                        i++;
                    }
                }
            }
            if (!inBlock && !line.empty()) {
                ans.push_back(line);
                line.clear();
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
