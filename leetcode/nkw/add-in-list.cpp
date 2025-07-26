//
//  add-in-list
//  BM11 链表相加(二)
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
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        head1 = reverse(head1), head2 = reverse(head2);

        ListNode dummy(-1);
        auto curr = &dummy;
        int carry = 0;
        while (head1 || head2 || carry > 0) {
            if (head1) {
                carry += head1->val;
                head1 = head1->next;
            }
            if (head2) {
                carry += head2->val;
                head2 = head2->next;
            }

            curr->next = new ListNode(carry % 10);
            curr = curr->next;
            carry = carry / 10;
        }

        auto ans = dummy.next;
        dummy.next = nullptr;
        return reverse(ans);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* list = nullptr;
        while (head) {
            auto next = head->next;
            head->next = list;
            list = head;
            head = next;
        }
        return list;
    }
};