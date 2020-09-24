//
//  insert-into-a-cyclic-sorted-list
//  https://leetcode.com/problems/insert-into-a-cyclic-sorted-list/
//
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

        // 能否在某位置后插入：
        // 以node为头的话，循环中只判断非尾的之前位置；
        // 这些位置都不行时，通过画图例可知，尾位置总是可行。
        auto p = node;
        while (p->next != node) {
            if (p->val <= x && x <= p->next->val) break;
            if (p->val > p->next->val && (x >= p->val || x <= p->next->val)) break;
            p = p->next;    
        }
        // 这时在p后插入
        auto nn = new ListNode(x);
        nn->next = p->next;
        p->next = nn;
        return nn;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
