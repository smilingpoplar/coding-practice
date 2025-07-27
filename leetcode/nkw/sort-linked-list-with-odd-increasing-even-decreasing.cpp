//
//  sort-linked-list-with-odd-increasing-even-decreasing
//  NC207 排序奇升偶降链表
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *sortLinkedList(ListNode *head) {
        auto l = split(head);
        l[1] = reverse(l[1]);
        return merge(l[0], l[1]);
    }

    vector<ListNode *> split(ListNode *head) {
        if (!head) return {nullptr, nullptr};
        // 奇偶位分离
        ListNode dummyOdd(-1), dummyEven(-1);
        auto odd = &dummyOdd, even = &dummyEven;
        while (head) {
            odd->next = head;
            odd = odd->next;
            even->next = head->next;
            even = even->next;
            head = even ? even->next : nullptr;
        }
        odd->next = nullptr;

        return {dummyOdd.next, dummyEven.next};
    }

    ListNode *reverse(ListNode *head) {
        ListNode dummy(-1);
        auto p = &dummy;
        while (head) {
            auto next = head->next;
            head->next = p->next;
            p->next = head;
            head = next;
        }
        return dummy.next;
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        auto p = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};