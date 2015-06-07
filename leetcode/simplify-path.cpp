//
//  simplify-path
//  https://leetcode.com/problems/simplify-path/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack; // 用栈存储解析出的部分
        istringstream iss(path);
        string part;
        while (getline(iss, part, '/')) {
            if (part.empty() || part == ".") continue;
            if (part == "..") {
                if (!stack.empty()) stack.pop_back();
                continue;
            }
            stack.push_back(part);
        }
        if (stack.empty()) return "/";
        ostringstream oss;
        for (const auto &part : stack) {
            oss << "/" << part;
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.simplifyPath("/a/./b/../../c/");
    
    return 0;
}
