//
//  verify-preorder-serialization-of-a-binary-tree
//  https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // 想象扫描串并构建树，在扫描串的过程中要确保"叶节点数<内节点数+1"，
        // 一旦"叶节点数=内节点数+1"则树已构建好不能再扩展，要确保扫描完。
        // 设diff=叶节点数-内节点数，扫描过程中确保diff<1，一旦diff==1确保扫描完。
        const int N = preorder.size();
        int diff = 0, i = 0;
        while (i < N) {
            if (preorder[i++] == '#') diff++;
            else diff--;
            if (diff == 1) break;

            // 向前直到','
            while (i < N && preorder[i] != ',') i++;
            if (i < N) i++;
        }
        return i == N && diff == 1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
