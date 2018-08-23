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
        // 设diff=叶节点数-内节点数。扫描串的过程中确保diff<1，
        // 一旦diff==1则树已构建好不能再扩展，此时确保扫完整串。
        const int N = preorder.size();
        int i = 0, diff = 0;
        while (i < N) {
            if (preorder[i++] == '#') diff++;
            else diff--;
            if (diff == 1) break;

            while (i < N && preorder[i] != ',') i++;
            if (i < N) i++;
        }
        return diff == 1 && i == N;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
