//
//  plus-one-linked-list
//  https://leetcode.com/problems/plus-one-linked-list/
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
    ListNode* plusOne(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        // 找最后一个!=9（不进位）的位置
        ListNode *found;
        for (auto p = dummy; p; p = p->next) {
            if (p->val != 9) found = p;
        }
        // found位置加1，后面位置全变0
        found->val += 1;
        for (auto p = found->next; p; p = p->next) {
            p->val = 0;
        }
        // 如果dummy后全是9，found=dummy，dummy->val==1
        if (dummy->val != 0) return dummy;
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
