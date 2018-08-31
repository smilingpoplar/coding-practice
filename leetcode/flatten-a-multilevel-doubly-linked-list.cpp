//
//  flatten-a-multilevel-doubly-linked-list
//  https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        for (auto *node = head; node; node = node->next) {
            if (node->child) {
                auto childHead = node->child, childTail = node->child;
                while (childTail->next) childTail = childTail->next;
                node->child = NULL;
                
                auto next = node->next;
                node->next = childHead;
                childHead->prev = node;
                childTail->next = next;
                if (next) next->prev = childTail;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
