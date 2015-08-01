//
//  delete-node-in-a-linked-list
//  https://leetcode.com/problems/delete-node-in-a-linked-list/
//
//  Created by smilingpoplar on 15/8/1.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }
};

int main(int argc, const char * argv[]) {
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(3);
    auto l4 = new ListNode(4);
    auto l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    Solution solution;
    solution.deleteNode(l3);
    for (auto node = l1; node != NULL; node = node->next) {
        cout << node->val << " ";
    }
    
    return 0;
}
