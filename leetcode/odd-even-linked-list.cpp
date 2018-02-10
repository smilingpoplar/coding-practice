//
//  odd-even-linked-list
//  https://leetcode.com/problems/odd-even-linked-list/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode *even = head;
        ListNode *odd = head->next;
        ListNode *oddHead = odd;
        // 把odd节点单独拎出来
        while (odd && odd->next) {
            even->next = odd->next;
            even = even->next;
            odd->next = even->next;
            odd = odd->next;
        }
        even->next = oddHead;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
