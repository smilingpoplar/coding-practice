//
//  add-two-numbers-ii
//  https://leetcode.com/problems/add-two-numbers-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode *list = NULL;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            if (!s1.empty()) {
                carry += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                carry += s2.top();
                s2.pop();
            }
            
            auto node = new ListNode(carry % 10);
            node->next = list;
            list = node;
            carry /= 10;
        }
        return list;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
