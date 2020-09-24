//
//  k-th-symbol-in-grammar
//  https://leetcode.com/problems/k-th-symbol-in-grammar/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        // 相当于二叉树，0分叉成0和1，1分叉成1和0
        // 可以看到左子节点和父节点相同，右子节点和父节点相反
        if (N == 1) return 0; // 根节点
        int parent = kthGrammar(N - 1, (K + 1) / 2);
        return (K % 2 == 1) ? parent : !parent; 
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
