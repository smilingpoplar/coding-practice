//
//  delete-duplicates
//  BM16 删除有序链表中重复的元素-II
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(-1);
        dummy.next = head;

        auto prev = &dummy;
        auto curr = prev->next;
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                // 删除所有连续相同值
                auto p = curr;
                while (p->next && p->val == p->next->val) {
                    p = p->next;
                }
                prev->next = p->next;
            } else {
                prev = prev->next;
            }
            curr = prev->next;
        }

        return dummy.next;
    }
};
