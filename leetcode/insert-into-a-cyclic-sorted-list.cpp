//
//  insert-into-a-cyclic-sorted-list
//  https://leetcode.com/problems/insert-into-a-cyclic-sorted-list/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    ListNode* insert(ListNode* node, int x) {
        if (!node) {
            auto nn = new ListNode(x);
            nn->next = nn;
            return nn;
        }
        auto p = node;
        while (p->next != node) {
            if (p->val <= x && x <= p->next->val) break;
            if (p->val > p->next->val && (x >= p->val || x <= p->next->val)) break; // p指向最大值
            p = p->next;    
        }
        // 接在p后
        auto nn = new ListNode(x);
        nn->next = p->next;
        p->next = nn;
        return nn;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
