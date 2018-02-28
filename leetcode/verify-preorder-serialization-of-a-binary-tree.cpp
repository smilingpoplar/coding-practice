//
//  verify-preorder-serialization-of-a-binary-tree
//  https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // 设diff=叶节点数-内节点数。从左到右扫描串，过程中叶节点数<内节点数+1，
        // 一旦叶节点数=内节点数+1则树构建好不能再扩展。
        istringstream iss(preorder);
        string s;
        int diff = 0;
        while (getline(iss, s, ',')) {
            if (s == "#") diff++;
            else diff--;
            if (diff == 1) break;
        }
        return diff == 1 && iss.eof();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
