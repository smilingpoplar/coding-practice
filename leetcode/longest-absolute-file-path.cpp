//
//  bulb-switcher
//  https://leetcode.com/problems/bulb-switcher/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
        while (getline(iss, line)) {
            int indent = 0;
            while (line[indent] == '\t') indent++;
            while (stk.size() > indent) stk.pop(); // 确保压栈时紧接着父目录位置
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
