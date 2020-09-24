//
//  longest-absolute-file-path
//  https://leetcode.com/problems/longest-absolute-file-path/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream iss(input);
        string line;
        stack<int> stk;
        int ans = 0;
        while (getline(iss, line)) { // 遍历\n每行路径，并将绝对路径长压栈
            int indent = 0;
            while (line[indent] == '\t') indent++;
            while (stk.size() > indent) stk.pop(); // 父目录数等于缩进数
            int filelen = line.size() - indent;
            int pathlen = (stk.empty() ? 0 : stk.top() + 1) + filelen; // 1是分隔符长
            stk.push(pathlen);
            if (line.find(".") != string::npos) ans = max(ans, pathlen);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
