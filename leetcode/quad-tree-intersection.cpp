//
//  quad-tree-intersection
//  https://leetcode.com/problems/quad-tree-intersection/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        // 某树是叶子，值为T则合后为T、值F则合后为另一树
        if (!quadTree1) return quadTree2;
        if (!quadTree2) return quadTree1;
        if (quadTree1->isLeaf) return quadTree1->val ? quadTree1 : quadTree2;
        if (quadTree2->isLeaf) return quadTree2->val ? quadTree2 : quadTree1;
        // 都不是叶子，则相应区域合并
        auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        // 全是叶子且值相同时合并成新叶子
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
            bool val = tl->val;
            if (val == tr->val && val == bl->val && val == br->val) {
                return new Node(val, true, NULL, NULL, NULL, NULL);
            }
        }
        return new Node(false, false, tl, tr, bl, br);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
