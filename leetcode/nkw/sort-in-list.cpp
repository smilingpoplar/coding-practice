//
//  sort-in-list
//  BM12 单链表的排序
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
    ListNode* sortInList(ListNode* head) {
        if (!head || !head->next) return head;
        auto fast = head->next, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto head2 = slow->next;
        slow->next = nullptr;

        return mergeTwoLists(sortInList(head), sortInList(head2));
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        auto curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                curr = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
